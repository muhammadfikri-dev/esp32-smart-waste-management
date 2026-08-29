/**
 * @file esp32-smart-waste-management.ino
 * @brief ESP32 Smart Waste Bin Fill-Level Telemetry
 * @author Muhammad Fikri
 * @license MIT
 */

#include <WiFi.h>

#define PIN_TRIG 5
#define PIN_ECHO 18
#define PIN_BUZZER 19
#define BIN_HEIGHT_CM 80.0 // Total height of the trash bin

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

float measureDistanceCm() {
 digitalWrite(PIN_TRIG, LOW);
 delayMicroseconds(2);
 digitalWrite(PIN_TRIG, HIGH);
 delayMicroseconds(10);
 digitalWrite(PIN_TRIG, LOW);

 long duration = pulseIn(PIN_ECHO, HIGH, 30000);
 if (duration == 0) return BIN_HEIGHT_CM;
 return (duration * 0.0343) / 2.0;
}

void setup() {
 Serial.begin(115200);
 pinMode(PIN_TRIG, OUTPUT);
 pinMode(PIN_ECHO, INPUT);
 pinMode(PIN_BUZZER, OUTPUT);

 Serial.println("ESP32 Smart Waste Monitor Initialized.");
}

void loop() {
 float distance = measureDistanceCm();
 float filledHeight = BIN_HEIGHT_CM - distance;
 if (filledHeight < 0) filledHeight = 0;
 float fillPercent = (filledHeight / BIN_HEIGHT_CM) * 100.0;
 if (fillPercent > 100.0) fillPercent = 100.0;

 Serial.printf("Distance: %.1f cm | Fill Level: %.1f %%
", distance, fillPercent);

 if (fillPercent >= 85.0) {
 Serial.println("[ALERT] Bin is near full capacity! Dispatching collector notification...");
 digitalWrite(PIN_BUZZER, HIGH);
 delay(200);
 digitalWrite(PIN_BUZZER, LOW);
 }

 delay(5000);
}

# 🗑️ ESP32 Smart Waste Management & Bin Level Monitor

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: ESP32](https://img.shields.io/badge/Platform-ESP32-blue.svg)](https://espressif.com/)
[![Cloud: Firebase](https://img.shields.io/badge/Cloud-Firebase%20Realtime%20DB-orange.svg)](#)
[![Portfolio: Laksanasoft](https://img.shields.io/badge/Portfolio-Laksanasoft-green.svg)](#)

An intelligent urban waste management and trash bin fill-level telemetry system. Designed for smart cities, campuses, and industrial facilities to optimize municipal trash collection routes and prevent overflow.

---

## 📌 Features

- **Non-Contact Fill-Level Detection:** Ultrasonic sensor (HC-SR04 / JSN-SR04T waterproof) measures garbage depth in real time.
- **Lid Tilt / Tamper Detection:** Built-in vibration and tilt sensing alerts operators if a bin falls or is tipped over.
- **Firebase Realtime Database Integration:** Synchronizes bin fill percentage, battery health, and coordinates directly with cloud dashboards.
- **Automated Route Optimization Readiness:** Sends alert webhooks when trash bins reach >85% capacity.

---

## 🔌 Hardware Connections

```
+------------------+---------------------+-------------------+
| ESP32 Pin        | Component Pin       | Function          |
+------------------+---------------------+-------------------+
| GPIO 5           | HC-SR04 TRIG        | Ultrasonic Pulse  |
| GPIO 18          | HC-SR04 ECHO        | Ultrasonic Return |
| GPIO 19          | Buzzer Positive     | Warning Sound     |
| GPIO 2           | Onboard Status LED  | Heartbeat Ping    |
+------------------+---------------------+-------------------+
```

---

## 📄 License
MIT License. Developed for **Laksanasoft Portfolio**.

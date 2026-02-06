# LPG Gas Leakage Detection System using ESP32 🚨🔥  
Smart detection for a critical safety problem.

This project implements a **real-time LPG gas leakage detection system** using an **ESP32**, **MQ-2 gas sensor**, visual indicators, an audible alarm, and a **16x2 LCD display**.

The system continuously monitors gas concentration and instantly alerts users when unsafe LPG levels are detected.

Simple design. Reliable logic. Life-saving purpose.

---

## 🧠 Project Overview
LPG leakage can lead to fire hazards and explosions if not detected early.  
This system uses the ESP32’s high-resolution ADC to accurately read gas concentration and trigger alerts immediately.

### Working Flow

The ESP32 provides better ADC resolution and future IoT expandability compared to basic microcontrollers.

---

## ⚡ Key Features
- Continuous LPG gas monitoring
- High-resolution ESP32 ADC (0–4095)
- Adjustable gas detection threshold
- Audible alert using buzzer
- Visual indication using red & green LEDs
- Real-time gas level display on LCD
- Clean, readable, and reliable ESP32 code

Suitable for **academic projects, demonstrations, and safety systems**.

---

## 🔧 Hardware Components
- ESP32 Development Board  
- MQ-2 Gas Sensor  
- Buzzer  
- Red LED (Gas detected)  
- Green LED (Safe condition)  
- 16x2 LCD Display (Parallel mode)  
- Resistors and jumper wires  

⚠️ ESP32 works on **3.3V logic**. Ensure MQ-2 output voltage is ADC-safe.

---

## 🔌 Pin Connections

### MQ-2 Sensor
| MQ-2 Pin | ESP32 GPIO |
|--------|------------|
| AO | GPIO 34 |
| VCC | 5V |
| GND | GND |

### Output Devices
| Device | ESP32 GPIO |
|------|-----------|
| Buzzer | GPIO 25 |
| Red LED | GPIO 26 |
| Green LED | GPIO 27 |

### LCD (16x2)
| LCD Pin | ESP32 GPIO |
|--------|------------|
| RS | 23 |
| EN | 22 |
| D4 | 21 |
| D5 | 19 |
| D6 | 18 |
| D7 | 5 |

---

## 💻 ESP32 Logic
- Reads analog gas value from MQ-2 sensor (0–4095)
- Displays gas level on LCD
- Compares reading with calibrated threshold
- Activates buzzer and red LED when gas is detected
- Displays SAFE status using green LED otherwise

---

## ⚙️ Threshold Configuration
```cpp
int threshold = 1800; // Adjust after calibration

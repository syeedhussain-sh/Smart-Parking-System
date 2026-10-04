Smart Parking Space Detection and Vehicle Indication System

An Arduino-based smart parking prototype that detects the availability of a monitored parking zone using an ultrasonic sensor and provides visual and audio indications through an LCD, LEDs, and buzzer.

## Overview

The **Smart Parking Space Detection and Vehicle Indication System** is designed to identify whether a monitored parking zone is **FREE** or **FULL**.

The system uses an **HC-SR04 ultrasonic sensor** mounted on an **SG90 servo motor**. The servo moves the sensor through different angles to scan the designated area. The measured distance is compared with a predefined threshold to determine the parking status.

The current prototype monitors a **single parking zone** using one ultrasonic sensor.

## Components Used

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- 16×2 I2C LCD
- Green LED
- Red LED
- Buzzer
- 1kΩ Resistors
- Breadboard
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|---|---|
| Servo Signal | D9 |
| HC-SR04 TRIG | D10 |
| HC-SR04 ECHO | D11 |
| Green LED | D6 |
| Red LED | D7 |
| Buzzer | D8 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## Working Principle

The system works in the following sequence:

1. The Arduino initializes the ultrasonic sensor, servo motor, LCD, LEDs, and buzzer.
2. The servo moves the ultrasonic sensor through different positions:
   
   `0° → 45° → 90° → 135° → 180°`

3. At each position, the HC-SR04 measures the distance to the object.
4. The measured distance is compared with a **20 cm threshold**.
5. If the detected distance is greater than 20 cm, the parking zone is considered **FREE**.
6. If the detected distance is 20 cm or less, the parking zone is considered **FULL**.
7. The result is displayed on the 16×2 LCD.
8. The corresponding LED provides a visual indication:
   - Green LED → FREE
   - Red LED → FULL
9. When the zone is FULL, the buzzer provides a short alert.
10. The angle, measured distance, and parking status are also displayed through the Serial Monitor.

## System Indications

### FREE Condition

When no vehicle or object is detected within the 20 cm threshold:

- LCD displays `SMART PARKING / FREE`
- Green LED blinks
- Red LED remains OFF
- Buzzer remains OFF
- Serial Monitor displays the measured distance and FREE status

### FULL Condition

When an object is detected within 20 cm:

- LCD displays `SMART PARKING / FULL`
- Red LED blinks
- Green LED remains OFF
- Buzzer gives a short alert
- Serial Monitor displays the measured distance and FULL status

## Development Process

The project was developed and tested step by step.

### 1. Ultrasonic Sensor Testing
The HC-SR04 was tested separately to verify accurate distance measurement.

### 2. Servo Motor Testing
The SG90 servo was tested to ensure that it could move through the required angles.

### 3. Ultrasonic and Servo Integration
The ultrasonic sensor was mounted with the servo and tested while scanning different angles.

### 4. LED Integration
Green and red LEDs were added to provide visual parking-status indications.

### 5. LCD Integration
The 16×2 I2C LCD was added to display the system status and parking condition.

### 6. Simple Parking System
The sensor, servo, LCD, LEDs, and buzzer were combined into a basic parking detection system.

### 7. Final Smart Parking System
The complete system was tested with FREE and FULL conditions, including Serial Monitor output.

## Project Media

The `Images` folder contains photographs of the hardware setup, sensor and servo arrangement, system-ready condition, and FREE/FULL indications.

The `Videos` folder contains demonstrations of the completed system under different operating conditions.

## Project Structure

```text
Smart-Parking-System/
│
├── Code/
│   ├── 01_Ultrasonic_Test/
│   ├── 02_Servo_Test/
│   ├── 03_Ultrasonic_Servo_Test/
│   ├── 04_Red_Green_LED_Test/
│   ├── 05_LCD_Working_Test/
│   ├── 06_Simple_Parking_System/
│   └── 07_Final_Smart_Parking_System/
│
├── Images/
│   ├── 01_Hardware_top_view.jpeg
│   ├── 02_Sensor_Servo_view.jpeg
│   ├── 03_System_ready.jpeg
│   ├── 04_Free_Condition.jpeg
│   ├── 05_Full_Condition.jpeg
│   ├── 06_Lcd_Free.jpeg
│   └── 07_Lcd_Full.jpeg
│
├── Videos/
│   ├── 01_System_Ready.mp4
│   ├── 02_Free_Condition.mp4
│   └── 03_Full_Condition.mp4
│
└── README.md
Future Improvements
The current prototype can be further improved by adding:
Multiple ultrasonic sensors for multiple parking slots
Automatic vehicle entry and exit detection
A larger parking-area monitoring system
IoT connectivity for remote parking-status monitoring
Mobile or web-based parking-status display
Real-time parking-slot availability updates
Automated parking management
Data logging for parking usage
Integration with a larger smart-city parking system
Project Status
Completed and Tested
The current prototype successfully detects a monitored parking zone as FREE or FULL and provides LCD, LED, buzzer, and Serial Monitor indications.
Author
Syed Hussain SH
B.E. Electronics and Communication Engineering
Sri Shakthi Institute of Engineering and Technology

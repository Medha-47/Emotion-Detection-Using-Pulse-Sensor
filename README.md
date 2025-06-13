# Emotion Detection Using Pulse Sensor

A simple and affordable Arduino-based system to detect human emotional states using a **pulse sensor**. This project estimates the user's emotional state (Calm, Normal, Stressed, or Happy) based on **real-time BPM (beats per minute)** and provides feedback via an **LCD display** and colored **LEDs**.

## 🧠 Project Overview

This system uses heart rate variability to estimate emotional conditions:
- **Calm** – Yellow LED
- **Normal** – White LED
- **Stressed** – Red LED
- **Happy** – Green LED

The detected state is displayed on a **16x2 I2C LCD**, along with helpful suggestions.

## 🛠️ Technologies Used

- Arduino Uno  
- Pulse Sensor  
- 16x2 LCD (with I2C interface)  
- 4x LEDs (Red, White, Yellow, Green)  
- Jumper wires, breadboard, resistors

## ⚙️ How It Works

1. The **PulseSensor** measures real-time pulse data.
2. **BPM (Beats Per Minute)** is calculated using the PulseSensor Playground library.
3. Based on the BPM, the system classifies the emotion:
   - BPM < 65 → Calm
   - 65 ≤ BPM ≤ 85 → Normal
   - BPM > 85 → Stressed
   - BPM = 72 ± range → Happy 
4. The result is:
   - Displayed on the LCD.
   - Indicated with the corresponding LED.

## 📦 Libraries Required

Install these in the Arduino IDE:
- `PulseSensor Playground`  
- `LiquidCrystal_I2C`

## 📄 Code

The full Arduino sketch is provided in `EmotionDetection.ino`. Key components:
```cpp
#include <PulseSensorPlayground.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

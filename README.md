# 🔆 Smart Adaptive Lamp with Arduino, Voice, and Pulse Sensor

This is a **Smart Adaptive Lamp** project that can automatically adjust its brightness and power state based on **voice input**, **pulse sensor**, and **movement inputs** using **Arduino** and various sensors.

> 🛠️ This project was created to fulfill the **Final Project requirement** for the course **Embedded Intelligent System** at **Universitas Singaperbangsa Karawang**.I

---

## 🎯 Features

- ✅ Voice-controlled ON/OFF using Python + microphone
- ❤️ Pulse-based brightness adjustment: 
- 🔘 Optional manual button input for toggling ON/OFF using ultrasonic sensor
- 🔆 Uses **AC Dimmer Module** to adjust brightness of AC lamp
- 🔗 Controlled entirely by Arduino

---

## 🧰 Hardware Requirements

| Component                | Description                                 |
|-------------------------|---------------------------------------------|
| Arduino Uno/Nano        | Main microcontroller                        |
| AC Dimmer Module        | For adjusting AC lamp brightness            |
| Lampu AC Dimmable       | Output lamp                                 |
| Pulse Sensor            | For heart rate input                        |
| Microphone (Laptop/USB) | For voice input via Python                  |
| Relay (optional)        | If only doing ON/OFF (not needed with dimmer) |
| Resistor 220–330Ω       | For LED testing                             |
| Jumper wires & Breadboard | Basic connections                        |

---

## 🖥️ Software Requirements

- Arduino IDE
- Python 3.7+
- Python Libraries:
  ```bash
  pip install pyserial speechrecognition pyaudio


## 🔁 How It Works

1. **Voice Input (via Python)**:

   * Captured by laptop microphone
   * Converted to text with `speech_recognition`
   * Sent to Arduino via serial port

2. **Pulse Sensor**:

   * Connected to Arduino analog pin
   * Used to control brightness while lamp is ON

3. **Arduino**:

   * Receives commands from voice or pulse
   * Sends appropriate PWM to AC Dimmer Module


## 📚 Note

⚠️ This system involves **220V AC** for real lamp control. Please:

* Use **dimmable LED lamps**
* Avoid touching AC parts while powered
* Test using an LED first if unsure

---

## 👥 Credits

This project was created by:

- Ayang Nova Anggraeni (me)

My teammates :
- Ariella Chandra Naya
- Erika Sita Dewi
- Julia Ayu Dewi Siagian

📍 Submitted as part of the **Embedded Intelligent System Final Project**,
Faculty of Computer Science, **Universitas Singaperbangsa Karawang (UNSIKA)**.

---

## 📄 License

This repository is for **educational purposes only**.
Feel free to modify or expand for personal learning.

---

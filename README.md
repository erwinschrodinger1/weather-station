## Weather Station Prototype with ESP32 and Cloud Logging

### Demo Video
https://youtu.be/XDWKrwy0qfI?si=F-4f__n14TOAoldB

### Introduction

This project outlines the development of a weather station prototype using readily available components. The core of the system is an ESP32 microcontroller, which interfaces with a DHT22 sensor for temperature and humidity readings. A 16x2 I2C LCD display provides local data visualization, while ThingSpeak facilitates cloud-based data logging.

### Components

* **ESP32 Dev Module:** This versatile microcontroller boasts a powerful dual-core processor, built-in Wi-Fi and Bluetooth, and extensive peripheral support, making it ideal for IoT projects.
* **DHT22 Sensor:** This cost-effective sensor measures both temperature and humidity with digital communication, simplifying integration with microcontrollers. It offers accuracy within ±0.5°C for temperature and ±2% for humidity, covering a wide range of environments (-40°C to 80°C temperature, 0-100% humidity).
* **16x2 I2C LCD Display:** This compact text display features 16 columns and 2 rows of LEDs controlled via I2C for easy connection to microcontrollers.

### Simulation Details

The components were virtually connected in Wokwi, a web-based platform for simulating and programming microcontrollers, devices, and code. Wokwi supports various programming languages like Rust, MicroPython, and C++.

**Pin Configuration:**

| Component (Pin) | ESP32 (Pin) |
|---|---|
| DHT22 VCC | +5V |
| DHT22 GND | GND |
| DHT22 SDA | 33 |
| LCD VCC | +5V |
| LCD GND | GND |
| LCD SDA | 24 |
| LCD SCL | 22 |

**Note:** Fritzing or schematic diagrams can be created externally and included as images in this section.

### Functionality Testing

Wokwi allows for dynamic sensor value adjustments during simulation. This feature was used to verify data transmission to both the LCD display and the cloud (ThingSpeak) by modifying simulated temperature and humidity values.

### Conclusion

This project successfully designed a weather station prototype utilizing an ESP32 microcontroller, a DHT22 sensor, an I2C LCD display, and ThingSpeak for cloud logging. Wokwi simulations verified data transmission with dynamic sensor value adjustments. Future steps involve constructing the physical station, real-world testing, and potentially developing a user-friendly web interface for clear data visualization.

![2024-06-2023-22-34-ezgif com-video-to-gif-converter(1)](https://github.com/erwinschrodinger1/weather-station/assets/81609547/97a9cd2f-cad1-4cd2-884a-630dc53418b7)

![image](https://github.com/erwinschrodinger1/weather-station/assets/81609547/31cc1d42-c168-4c36-bc7f-c0a921e310d7)


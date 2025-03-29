# Ardunino Nano ESP32 C++

## Getting Started

### Arduino IDE

Please configure the Arduino IDE based on the following steps:

1. `Tools > Board` select `Arduino Nano ESP32` (download using board manager if necessary)
2. `Tools > Port` select a serial port like `/dev/ttyACM0`
3. `Tools > USB Mode` select `Debug mode (Hardware CDC)`
4. `Tools > Programmer` select `Esptool`

Compile and upload the sketch using the following steps:

1. `Sketch > Upload Using Programmer`

### Arduino-CLI

Follow the [getting started](https://arduino.github.io/arduino-cli/1.2/getting-started/) instructions of the [Arduino CLI](https://arduino.github.io/arduino-cli/1.2/).

```bash
# Compile and upload the `Blink` sketch
arduino-cli compile -p /dev/ttyACM0 -P esptool -u --fqbn arduino:esp32:nano_nora Blink 
```
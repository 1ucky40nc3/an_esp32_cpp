# Ardunino Nano ESP32 C++

## Getting Started

### Arduino IDE

We use the Arduino IDE for building, uploading and serial plotting/monitoring.

#### Configure the Arduino Nano ESP32

Please configure the Arduino IDE based on the following steps:

1. `Tools > Board` select `Arduino Nano ESP32` (download using board manager if necessary)
2. `Tools > Port` select a serial port like `/dev/ttyACM0`
3. `Tools > USB Mode` select `Debug mode (Hardware CDC)`
4. `Tools > Programmer` select `Esptool`

#### Set Arduino IDE Preferences

Please configure the Ardunio IDE preferences for a smooth [development experience](#development-using-the-arduino-ide).

1. `File > Preferences... > Sketchbook location` select the current location of this repo (this enables the use of custom libraries)
2. `File > Preferences... > Auto save` enable the auto save feature 

### VSCode

We use VSCode for code formatting, linting.

#### Configure VSCode Extension

Please install the recommended VSCode extensions from the [extensions.json](extensions.json) file.

## Build

### Build Using the Arduino-CLI

Follow the [getting started](https://arduino.github.io/arduino-cli/1.2/getting-started/) instructions of the [Arduino CLI](https://arduino.github.io/arduino-cli/1.2/).

```bash
# Compile and upload the `Blink` sketch
arduino-cli compile -p /dev/ttyACM0 -P esptool -u --fqbn arduino:esp32:nano_nora Blink 
```

### Build Using the Arduino IDE

Compile and upload the sketch using the following steps:

1. `Sketch > Upload Using Programmer`

## Development

### Development Using the Arduino IDE and VSCode

The following development setup uses:

- Arduino IDE: building, uploading and serial plotting/monitoring and
- VSCode: formatting, linting of code and libraries

Use the [Arduino IDE setup guide](#arduino-ide) and the [VSCode setup guide](#vscode) to get started. Development processes are outline below.

This development strategy has the following goals:

- use well behaved tools to compile and upload code to the Arduino Nano ESP32
- enable the testing of code on the deployment hardware
- enable the automatic formatting of code

During the development you need to have three windows open:

1. An Arduino IDE window with the deployment sketch (e.g. [Blink](./Blink/Blink.ino))
2. An Arduino IDE window with the testing sketch (e.g. [Test](./Test/Test.ino))
3. A VSCode windows for the development of a library shared for testing and deloyment sketches, formatting and linting

Use the first windows to deploy the code on the production hardware. The second windows is used to test the code on the production hardware. The last window is used for the development and automatic formatting.

#### Formatting

We use the [default Ardiuno IDE formatting config](https://raw.githubusercontent.com/arduino/tooling-project-assets/main/other/clang-format-configuration/.clang-format) and VSCode to automatically apply the formatting on save. You can download the default `.clang-format` file like this:

```bash
wget https://raw.githubusercontent.com/arduino/tooling-project-assets/main/other/clang-format-configuration/.clang-format -O Blink/.clang-format
```

You can do the automatic formatting by going to `Tools > Auto Format` or using the `Str + T` keyboard shortcut.


## Troubleshooting

#### Reset the Arduino bootloader on the Nano ESP32

Please follow the official instructions from the [article](https://support.arduino.cc/hc/en-us/articles/9810414060188-Reset-the-Arduino-bootloader-on-the-Nano-ESP32)!

In cases where the article can't be use this the following instructions:

1.  **Enter Firmware Download Mode:**
    * Connect a jumper wire between the **GND** and **B1** pins on your Arduino Nano ESP32.
    * Observe that the RGB LED on the board should illuminate with a green color.
    * While the **GND** and **B1** pins are shorted, press the white **RST** button located on the top of the board. This action resets the board into firmware download mode.
    * Remove the jumper wire. The RGB LED should now display a purple color, indicating the board is in download mode.

2.  **Configure Arduino IDE:**
    * Open the Arduino IDE.
    * Navigate to **Tools > Port** and select the port associated with your Arduino Nano ESP32. It might be identified as a generic ESP32 board.
    * Go to **Tools > Board** and select **Arduino ESP32 Boards > Arduino Nano ESP32**. Alternatively, if you have the full ESP32 package installed, choose **esp32 > Arduino Nano ESP32**.
    * Open the **Tools > Programmer** menu.
    * Select **Esptool**.

3.  **Upload Firmware:**
    * Open your desired firmware sketch in the Arduino IDE.
    * Select **Sketch > Upload Using Programmer**.
    * Wait for the upload process to complete. You'll know it's finished when you see the following lines in the Arduino IDE console:

        ```
        Leaving...
        Hard resetting via RTS pin...
        ```

4.  **Exit Firmware Download Mode:**
    * Press the **RST** button on the top of the board to exit firmware download mode and run the newly uploaded firmware.


**Notes**:

* The RGB LED color change is a visual indicator of the board's state.
* The "Esptool" programmer is essential for uploading firmware to ESP32 boards.
* If the correct port for the Arduino Nano ESP32 is not visible, check your USB connection and drivers.
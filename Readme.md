# Control relays using alexa.

### Materials Required to run this project
- ESP 8266 (__tested on NodeMCU__)
- 4 channel relay board
- Alexa device (__tested with original Echo Dot__)
- A common Wifi network to connect Echo Device and ESP Module

### Steps to compile and flash the project

Note: This project is created using [PlatformIO](https://platformio.org/) and [VSCode]{https://code.visualstudio.com/}. So the further steps assume you have PlatformIO core installed on your system. If not please follow the installation guide for your system at [PlatformIO Core installation](https://platformio.org/install/cli).

- Clone the repository
```bash
git clone https://github.com/vakshit/alexa-controls-esp8266.git
```

- Change the device names and pin in the `src/main.cpp` file
- Use the PlatformIO VSCode extension to upload to the device or from the terminal run
```bash
platformio run --target upload
```

Note: You need the appropriate driver for the board to be installed for the binary to be flashed successfully.
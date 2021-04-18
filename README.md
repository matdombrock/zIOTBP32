# zIOTBP32
**INTERNET OF THINGS BOILERPLATE FOR ESP23**

*An Arduino compatible IOT boilerplate system for the ESP32 development board. A simple to use drop-in solution for bootstrapping IOT functionality on any ESP32 project.*

## Depends On
* [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
* [AsyncTCP](https://github.com/me-no-dev/AsyncTCP)
* [Latest ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
  
## Features
* Add to your project with just 3 lines of code
* Super fast async web server
* Automatic soft AP for configuring WiFi

## About zIOTBP32
This is a very low abstraction boilerplate to easily get the [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) library running in your project. Because of this, the included documentation here will be light. Please see the excellent [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) documentation for more info and advanced usage.

## Setup

*Note: This is not a library and is not meant to be installed like a library. This is meant to be copied into your project directory. The files contained in the `zIOTBP32` directory can be customized by advanced users.*

### Download and install:
Download this repo and put the `zIOTBP32` folder into your project directory.
```
your-project/
--zIOTBP32/
--your_sketch.ino
```
  
### Add the boilerplate to your sketch:
```cpp
#include <Arduino.h>
#include "zIOTBP32/zsetupBP.h"

void setup() {
  setupBP();
}

void loop() {
  loopBP();
}
```

### Routes
A simple route method might look like this:
```cpp
void r_example(AsyncWebServerRequest *request){
  String message = "Hello World";
  request->send(200, "text/plain", message);
}
```

It can be added to the application at any time by doing something like this:
```cpp
server.on("/example", HTTP_GET, r_example);
```

## Advanced Setup
```cpp
void setupBP(const char *apName="ESP SETUP", const char *ssid=NULL, const char *pkey=NULL)
```

You can provide the `setupBP()` function with 3 optional arguments to set the soft AP name as well as the default WiFi credentials.
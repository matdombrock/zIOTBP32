#line 1 "h:\\LAB\\Arduino\\zIOTBP32\\simple_server.ino"
#include <Arduino.h>
#include "zIOTBP32/zsetupBP.h"// Required

#line 4 "h:\\LAB\\Arduino\\zIOTBP32\\simple_server.ino"
void setup();
#line 26 "h:\\LAB\\Arduino\\zIOTBP32\\simple_server.ino"
void loop();
#line 4 "h:\\LAB\\Arduino\\zIOTBP32\\simple_server.ino"
void setup() {
    Serial.begin(115200);
    /*
    * void setupBP(const char *apName="ESP SETUP", const char *ssid=NULL, const char *pkey=NULL)
    */
    setupBP("ESP SETUP", "HERSHEL", "meowmeow");// Required
    // EXAMPLE ROUTES
    // Check system uptime
    server.on("/uptime", HTTP_GET, r_uptime);
    // Test reading content from PROGMEM
    server.on("/test", HTTP_GET, r_test);
    // Scan local WIFI networks
    server.on("/scan", HTTP_GET, r_scan);
    // Get system status info
    server.on("/status", HTTP_GET, r_status);
    // Send a GET request to <IP>/get?message=<message>
    server.on("/get", HTTP_GET, r_get);
    // Send a POST request to <IP>/post with a form field message set to <message>
    server.on("/post", HTTP_POST, r_post);
    //your other setup stuff...
}

void loop() {
  //
  loopBP();// Required
  //
}

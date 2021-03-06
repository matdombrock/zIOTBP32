/* 
Handles setup of the main boilerplate code.
Note: You probably don't want to change this file.
*/
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>

// Custom 
#include "zCaptiveRequestHandler.h"
#include "zstandardRoutes.h"
#include "zroutes.h"
#include "zhttpGet.h"
#include "zsetupWIFI.h"
#include "zloopBP.h"

AsyncWebServer server(80);
DNSServer dnsServer;
int timer = millis();

void setupBP(const char *apName="ESP SETUP", const char *ssid=NULL, const char *pkey=NULL){
  WiFi.mode(WIFI_MODE_APSTA);
  if(ssid != NULL && pkey != NULL){
    bool running = setupWIFI(ssid, pkey);
    if(running){
      int httpCode;
      String payload;
      HTTPGET("https://raw.githubusercontent.com/matdombrock/AfterMath/master/src/data/tools.json",httpCode, payload);
      Serial.println(httpCode);
      Serial.println(payload);
    }
  }
  setupStandardRoutes(server);
  WiFi.softAP(apName);
  dnsServer.start(53, "*", WiFi.softAPIP());
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  server.begin();
}
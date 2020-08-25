#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <AutoConnect.h>

#include "WiFiDevice.h"
#include "Logger.h"
#include "Lamp.h"
#include "Handlers.h"

ESP8266WebServer server(80);
AutoConnect      Portal(server);
Logger           logger("Lamp");
Lamp             lamp(RED_PIN, GREEN_PIN, BLUE_PIN, &logger);

void setup() {
  Serial.begin(115200);
  logger.setEnabled(true);
  
  server.addHandler(new OnUpdateHandler(&lamp));
  server.addHandler(new HueUpdateHandler(&lamp));
  server.addHandler(new SaturationUpdateHandler(&lamp));
  server.addHandler(new BrightnessUpdateHandler(&lamp));

  Portal.config("RGBLights", "rgblights");
  
  if (Portal.begin()) {
    Serial.println("HTTP server:" + WiFi.localIP().toString());
  }
}

void loop() {
  Portal.handleClient();
}

#ifndef HANDLERS_H_
#define HANDLERS_H_

#include <ESP8266WebServer.h>
#include "Lamp.h"

class OnUpdateHandler : public RequestHandler {
  Lamp * lamp;

public:
  OnUpdateHandler(Lamp * lamp) {
    this->lamp = lamp;
  }
  
  bool canHandle(HTTPMethod method, String uri) { 
    return uri != nullptr && uri.startsWith("/on/");
  }

  bool handle(ESP8266WebServer& server, HTTPMethod requestMethod, String requestUri) {   
    // Find value in uri
    int on_value;
    int arg_count = sscanf(requestUri.c_str(), "/on/%d", &on_value);

    // Update lamp
    lamp->setOn(on_value);
    
    return arg_count == 1;
  }
};

class HueUpdateHandler : public RequestHandler {
  Lamp * lamp;

public:
  HueUpdateHandler(Lamp * lamp) {
    this->lamp = lamp;
  }
  
  bool canHandle(HTTPMethod method, String uri) { 
    return uri != nullptr && uri.startsWith("/hue/");
  }

  bool handle(ESP8266WebServer& server, HTTPMethod requestMethod, String requestUri) {   
    // Find value in uri
    int hue_value;
    int arg_count = sscanf(requestUri.c_str(), "/hue/%d", &hue_value);

    // Update lamp
    lamp->setHue(hue_value);
    
    return arg_count == 1;
  }
};

class SaturationUpdateHandler : public RequestHandler {
  Lamp * lamp;

public:
  SaturationUpdateHandler(Lamp * lamp) {
    this->lamp = lamp;
  }
  
  bool canHandle(HTTPMethod method, String uri) { 
    return uri != nullptr && uri.startsWith("/saturation/");
  }

  bool handle(ESP8266WebServer& server, HTTPMethod requestMethod, String requestUri) {   
    // Find value in uri
    int saturation_value;
    int arg_count = sscanf(requestUri.c_str(), "/saturation/%d", &saturation_value);

    // Update lamp
    lamp->setSaturation(saturation_value);
    
    return arg_count == 1;
  }
};

class BrightnessUpdateHandler : public RequestHandler {
  Lamp * lamp;

public:
  BrightnessUpdateHandler(Lamp * lamp) {
    this->lamp = lamp;
  }
  
  bool canHandle(HTTPMethod method, String uri) { 
    return uri != nullptr && uri.startsWith("/brightness/");
  }

  bool handle(ESP8266WebServer& server, HTTPMethod requestMethod, String requestUri) {   
    // Find value in uri
    int brightness_value;
    int arg_count = sscanf(requestUri.c_str(), "/brightness/%d", &brightness_value);

    // Update lamp
    lamp->setBrightness(brightness_value);
    
    return arg_count == 1;
  }
};

#endif

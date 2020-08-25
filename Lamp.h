#ifndef LAMP_H_
#define LAMP_H_

#include "hsv2rgb.h"

class Lamp {
  int redPin;
  int greenPin;
  int bluePin;

  int on;
  int hue;
  int brightness;
  int saturation;

  Logger * logger;

public:
  Lamp(int redPin, int greenPin, int bluePin, Logger * logger) {
    this->redPin = redPin;
    this->greenPin = greenPin;
    this->bluePin = bluePin;
    this->logger = logger;
  }

  void dump() {
    int colors[3];
    getRGB(this->hue, this->saturation * 2.55, this->brightness * 2.55, colors);
  
    if (this->on != 0) {
      analogWrite(this->redPin, colors[0]);
      analogWrite(this->greenPin, colors[1]);
      analogWrite(this->bluePin, colors[2]);
     } else {
      analogWrite(this->redPin, 0);
      analogWrite(this->greenPin, 0);
      analogWrite(this->bluePin, 0);
     }

     logger->println("Hue: " + this->hue);
     logger->println("Saturation: " + this->saturation);
     logger->println("Brightness: " + this->brightness);
  }

  void setOn(int on) {
    this->on = on;
    dump();
  }

  void setHue(int hue) {
    this->hue = hue;
    dump();
  }

  void setSaturation(int saturation) {
    this->saturation = saturation;
    dump();
  }

  void setBrightness(int brightness) {
    this->brightness = brightness;
    dump();
  }
};

#endif

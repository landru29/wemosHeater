#include "heater_comm.h"
#include <ESP8266WiFi.h>
#include "led.h"

#define PLUS D1
#define MINUS D2


HeaterComm::HeaterComm() {
  setStatus(ZERO);
  pinMode(PLUS, OUTPUT);
  pinMode(MINUS, OUTPUT);
}

void HeaterComm::setStatus(HeaterStatus value) {
  status = value;

  switch (status) {
    case ZERO:
      digitalWrite(PLUS, LOW);
      digitalWrite(MINUS, LOW);
      Led::displayStatus(0);
      break;
    case POSITIVE:
      digitalWrite(MINUS, LOW);
      digitalWrite(PLUS, HIGH);
      Led::displayStatus(0b1111111111110000);
      break;
    case NEGATIVE:
      digitalWrite(PLUS, LOW);
      digitalWrite(MINUS, HIGH);
      Led::displayStatus(0b1111111111110000);
      break;
    case ALTERNATIVE:
      digitalWrite(PLUS, HIGH);
      digitalWrite(MINUS, HIGH);
      Led::displayStatus(0b1111111111110000);
      break;
    default:
      // Do nothing
      break;
  }
}




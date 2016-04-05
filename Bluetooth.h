/**
*	Bluetooth serial wrapper
**/

#ifndef Bluetooth_h
#define Bluetooth_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class Bluetooth
{
  public:
    Bluetooth(int pinTX = 10, int pinRX = 11, int vel = 9600);
    char send(char msg);
    char receive();
    bool available();
  private:
    SoftwareSerial *btserial;
};

#endif

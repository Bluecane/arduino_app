#include "Arduino.h"
#include "SoftwareSerial.h"
#include "Bluetooth.h"

/**
*  Consturctor
**/

Bluetooth::Bluetooth(int pinTX, int pinRX, int vel) {
  btserial = new SoftwareSerial(pinTX, pinRX);
  btserial->begin(vel);
}

/**
*  Send
**/
char Bluetooth::send(char msg) {
    btserial->write(msg);
    btserial->write(0xA);
    return msg;
}

bool Bluetooth::available() {
  return btserial->available();
}

/**
*  receive
**/
void Bluetooth::receive(char (*callback)(char)) {
  char dato;
  if (btserial->available() )
  {
    dato = btserial->read();
    callback(dato);
  }

}

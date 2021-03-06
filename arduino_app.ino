#include "Bluetooth.h"

#include <SoftwareSerial.h>

Bluetooth b(10 , 11);
// PIN 10 -> TXD (PIN 3 del lado componentes)
// PIN 11 -> RXD (PIN 2 del lado componentes) a través de divisor resistivo por 2.

char dato;         // variable para recibir datos desde el puerto serie

void setup() {                            
  Serial.begin(9600);      // Inicializa puerto serial hardware (USB)                               
  Serial.println("LISTO......");
}

void loop() {
  // Verificar si hay datos disponibles en el puerto serial HARDWARE (provenientes de la PC)
  if (Serial.available() )
  {
    //Leer dato desde la PC
    dato = Serial.read();
     // leer del puerto y guardar en dato
    b.send(dato); 

  }

  //respuesta cuando devuelve un dato 
  b.receive(readCallback); 
  
} 

char readCallback (char data) {
  Serial.write(data);
}


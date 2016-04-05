#include "Bluetooth.h"
#include "TimerTask.h"

#include <SoftwareSerial.h>

Bluetooth b(10 , 11);
TimerTask task1(1000);
TimerTask task2(1500);

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

  task1.tick(callback1);
  task2.tick(callback2);

  //respuesta cuando devuelve un dato 
  b.receive(readCallback); 
  
} 

void callback1(int count) {


  if(count > 10) {
    task1.desactivate();
    Serial.println("SE DETUVO CONTADOR 1");
    return;
  }

  Serial.write("Counter 1 > ");
  Serial.println(count);
 
}

void callback2(int count) {


  if(count > 5) {
    task2.desactivate();
    Serial.println("SE DETUVO CONTADOR 2");
    return;
  }

  Serial.write("Counter 2: > ");
  Serial.println(count);
 
}

char readCallback (char data) {
  Serial.write(data);
}


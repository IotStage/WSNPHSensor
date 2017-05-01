#include "WSN.h"
Ph ph(A0);

long temps;
void setup() {
  Serial.begin(9600);
  temps = millis();
}

void loop() {
 ph.updatePh();
 if(millis() - temps > 1000){
  Serial.println(ph.getMesure());
  temps=millis();
 }
 
}

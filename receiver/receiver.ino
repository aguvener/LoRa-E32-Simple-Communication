#include <Wire.h>
#include "LoRa_E32.h"

LoRa_E32 e32ttl(19, 18); // RX, TX

typedef  struct {
  int var1;
  int var2;
  int var3;
  int var4;
  int password;
} Signal;

Signal data;

void setup() {
  Serial.begin(9600);
  e32ttl.begin();
  delay(500);
}

void loop() {
  while (e32ttl.available()  > 1) {
    ResponseStructContainer rsc = e32ttl.receiveMessage(sizeof(Signal));
    data = *(Signal*) rsc.data;
    rsc.close();
    Serial.println(data.password);
    if ((int)(data.password) == 1881) {
      Serial.println(data.var1);
      Serial.println(data.var2);
      Serial.println(data.var3);
      Serial.println(data.var4);
    }
  }
}

#include <Wire.h>
#include "LoRa_E32.h"

LoRa_E32 e32ttl(19, 18); // RX, TX

int var1;
int var2;
int var3;
int var4;


typedef  struct {
  int var1;
  int var2;
  int var3;
  int var4;
  int password;
} Signal;

Signal data;

void setup(){
  Serial.begin(9600);
  e32ttl.begin();
  delay(500);
  data.password = 1881;
}

void loop(){
  data.var1 = var1;
  data.var2 = var2;
  data.var3 = var3;
  data.var4 = var4;

  Serial.println(sizeof(Signal));
  ResponseStatus rs = e32ttl.sendFixedMessage(0, 5, 4, &data, sizeof(Signal));
  Serial.println(rs.getResponseDescription());
}

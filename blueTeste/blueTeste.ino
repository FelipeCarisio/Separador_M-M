#include <SoftwareSerial.h>

SoftwareSerial bt(2,3);

void setup() 
{
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
  bt.print("c");
  bt.print("e");
  delay(1000);
}

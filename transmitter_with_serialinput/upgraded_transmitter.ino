#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "10011";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(115200);
}
void loop() {
  String text = "";
  char buf[]="";
  text = Serial.readString();
  text.toCharArray(buf,100);
  Serial.print(text);
//  char trans[]=text.toCharArrray(buf,100);
  radio.write(&buf,100);
  delay(1000);
}

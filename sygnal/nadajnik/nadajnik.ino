#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte adress[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(adress);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();

 // Serial.println("koniec setup");
}

void loop() {
  
  //Serial.println("+");
  char text[11] = {0};
  int x = analogRead(A0);
  int y = analogRead(A1);
  sprintf(text, "%d %d\n", x, y);
  Serial.println(strlen(text));
  radio.write(text, strlen(text));
  //Serial.println(x);
  //Serial.println(y);
  /*
  int i = 0;
  for(i = 0; i < 100; ++i) {
    radio.write(&i, sizeof(int));
    Serial.println(i);
    delay(500);
  } */
  
  
}

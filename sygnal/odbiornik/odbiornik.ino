#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte adress[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, adress);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

  Serial.println("koniec setup");
}

long old = 0;
void loop() {
  if (millis() > old + 500)
  {
    //Serial.println("a");
    old = millis() + 500;  
  }
  
  /*if(radio.available()) {
    char text[11] = {0};
    int x = 0;
    int y = 0;
    //Serial.println("b");
    radio.read(text, sizeof(text));
    //Serial.println(text); 
    sscanf(text, "%d %d", &x, &y);
    //Serial.println(x);
    //Serial.println(y);
  }*/
  int i = 0;
  if(radio.available()) {
     radio.read(&i, sizeof(int));
     Serial.println(i);
  }
}

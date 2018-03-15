#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte adress[6] = "00001";

int x = -1;
int y = -1;

int speed = 0;

int old_x = 0;
int old_y = 0;

int intabs(int a) {
  if(a >= 0) {
    return a;
  }
  else {
    return a * (-1);  
  }  
}

int is_close(int a, int b) {
  if(intabs(a - b) > 90) {
    return 0;  
  }  
  else {
    return 1;  
  }
}
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, adress);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

  digitalWrite(11, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(4, HIGH);
  
  if(radio.available()) {
    char text[10] = {0};
    radio.read(text, sizeof(text));
    sscanf(text, "%d %d", &x, &y);
  }
}


void loop() {
  int i = 0;
  if (x > 900 && is_close(old_x, x)== 0) {
    digitalWrite(11, HIGH); //chyba w przód
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(4, HIGH);

    for (i = 0; i < 151; i += 10) {
      analogWrite(3, i);
      analogWrite(5, i);
      analogWrite(10, i);
      analogWrite(13, i);
      delay(50);
    }
    speed = 150;
  }
  else if (x < 100 && x != -1 && is_close(old_x, x)== 0) {
    digitalWrite(11, LOW); // do tyłu
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(4, LOW);

    for (i = 0; i < 151; i += 10) {
      analogWrite(3, i);
      analogWrite(5, i);
      analogWrite(10, i);
      analogWrite(13, i);
      delay(50);
    }
    speed = 150;
    Serial.println("Przy s");
  }
  else if (y < 100 && y != -1 && is_close(old_y, y)== 0) {
    digitalWrite(11, LOW); // w lewo
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(4, HIGH);

    for (i = 0; i < 151; i += 10) {
      analogWrite(3, i);
      analogWrite(5, i);
      analogWrite(10, i);
      analogWrite(13, i);
      delay(50);
    }
    speed = 150;
    Serial.println("Przy a");
  }
  else if (y > 900 && is_close(old_y, y)== 0) {
    digitalWrite(11, HIGH); // prawo
    digitalWrite(9, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);

    for (i = 0; i < 151; i += 10) {
      analogWrite(3, i);
      analogWrite(5, i);
      analogWrite(10, i);
      analogWrite(13, i);
      delay(50);
    }
    speed = 150;
    //Serial.println("Przy d");
  }
  else if(x < 550 && x > 400 && y < 550 && y > 400 && (is_close(old_x, x)== 0 || is_close(old_y, y)== 0)) {
    if(speed == 0) {
      analogWrite(3, 0);
      analogWrite(5, 0);
      analogWrite(10, 0);
      analogWrite(13, 0);
      delay(50);
      //Serial.println("Ta petla gdy jest 32 i speed == 0");
    }
    else if(speed != 0) {
      for (i = 150; i >= 0; i -= 10) {
          analogWrite(3, i);
          analogWrite(5, i);
          analogWrite(10, i);
          analogWrite(13, i);
          delay(50);
      }
      //Serial.println("Ta petla gdy jest 32 i speed != 0");
    }
    
  }
 old_x = x;
 old_y = y;
 if(radio.available()) {
    char text[10] = {0};
    radio.read(text, sizeof(text));
    sscanf(text, "%d %d", &x, &y);
 }
 
 if((is_close(old_x, x)== 0 || is_close(old_y, y)== 0) && speed != 0) {
    for (i = 150; i >= 0; i -= 10) {
        analogWrite(3, i);
        analogWrite(5, i);
        analogWrite(10, i);
        analogWrite(13, i);
        delay(100);
    }
    speed = 0;
 }
}

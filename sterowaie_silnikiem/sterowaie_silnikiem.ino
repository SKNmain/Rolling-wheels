int incomingByte = 0;
int given = 0;
int speed = 0;
int old_given = 0;
int take_speed() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
  return incomingByte;
}

void setup() {
  Serial.begin(9600);

  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);

  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

  digitalWrite(11, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(4, HIGH);
  given = take_speed();
}


void loop() {
  int i = 0;
  if (given == 'w' && given != old_given) {
    digitalWrite(11, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(4, HIGH);

    for (i = 0; i < 151; i += 10) {
      analogWrite(3, i);
      analogWrite(5, i);
      analogWrite(10, i);
      analogWrite(8, i);
      delay(50);
    }
    speed = 150;
    Serial.println("Przy w");
  }
  else if (given == 's' && given != old_given) {
    digitalWrite(11, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(4, LOW);

    for (i = 0; i < 151; i += 10) {
      analogWrite(3, i);
      analogWrite(5, i);
      analogWrite(10, i);
      analogWrite(8, i);
      delay(50);
    }
    speed = 150;
    Serial.println("Przy s");
  }
  else if (given == 'a' && given != old_given) {
    digitalWrite(11, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);

    for (i = 0; i < 151; i += 10) {
      analogWrite(3, i);
      analogWrite(5, i);
      analogWrite(10, i);
      analogWrite(8, i);
      delay(50);
    }
    speed = 150;
    Serial.println("Przy a");
  }
  else if (given == 'd' && given != old_given) {
    digitalWrite(11, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(4, HIGH);

    for (i = 0; i < 151; i += 10) {
      analogWrite(3, i);
      analogWrite(5, i);
      analogWrite(10, i);
      analogWrite(8, i);
      delay(50);
    }
    speed = 150;
    Serial.println("Przy d");
  }
  else if(given == 32 && given != old_given) {
    if(speed == 0) {
      analogWrite(3, 0);
      analogWrite(5, 0);
      analogWrite(10, 0);
      analogWrite(8, 0);
      delay(50);
      Serial.println("Ta petla gdy jest 32 i speed == 0");
    }
    else if(speed != 0) {
      for (i = 150; i >= 0; i -= 10) {
          analogWrite(3, i);
          analogWrite(5, i);
          analogWrite(10, i);
          analogWrite(8, i);
          delay(50);
      }
      Serial.println("Ta petla gdy jest 32 i speed != 0");
    }
    
  }
 old_given = given;
 given = take_speed();
 if(given != old_given && speed != 0) {
    for (i = 150; i >= 0; i -= 10) {
        analogWrite(3, i);
        analogWrite(5, i);
        analogWrite(10, i);
        analogWrite(8, i);
        delay(100);
    }
    speed = 0;
    Serial.println("Ta petla na samym koncu");
 }
  /*int i = 0;
    for(i = 0; i < 251; i += 10) {
    analogWrite(3, i);
    analogWrite(5, i);
    analogWrite(10, i);
    analogWrite(8, i);
    delay(100);
    }
    for(i = 250; i >= 0; i -= 10) {
    analogWrite(3, i);
    analogWrite(5, i);
    analogWrite(10, i);
    analogWrite(8, i);
    delay(100);
    }*/

}

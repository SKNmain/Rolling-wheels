
void setup() {
 
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
}


void loop() { 
  int i = 0;
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
  }
}

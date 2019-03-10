#include <Servo.h>

Servo i;
Servo j;

// Οι εντολές για επανέναρξη της κυκλοφορίας
void goGreen() {
  i.write(90);
  j.write(90);
  // Red Led
  digitalWrite(5, LOW);
  // Orange Led
  digitalWrite(6, LOW);
  // Green Led
  digitalWrite(7, HIGH);
}


// Οι εντολές για διακοπή της κυκλοφοριας
void goRed() {
  // Red Led
  digitalWrite(5, LOW);
  // Orange Led
  digitalWrite(6, HIGH);
  // Green Led
  digitalWrite(7, LOW);
  delay(2000);
  // Red Led
  digitalWrite(5, HIGH);
  // Orange Led
  digitalWrite(6, LOW);
  // Green Led
  digitalWrite(7, LOW);
  i.write(1);
  j.write(1);
  delay(500);
  while (analogRead(0) < 1015 && analogRead(1) < 1015) {
    delay(50);
  }
  delay(1500);
  goGreen();
}



void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  i.attach(8);
  j.attach(9);
    i.write(90);
  j.write(90);
  // Red Led
  digitalWrite(5, LOW);
  // Orange Led
  digitalWrite(6, LOW);
  // Green Led
  digitalWrite(7, HIGH);

}

void loop() {
    if (analogRead(0) > 1015 || analogRead(1) > 1015) {
      goRed();

    }
    delay(60);

}



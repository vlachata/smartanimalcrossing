#include <Servo.h>

Servo i;
Servo j;

// Οι εντολές για επανέναρξη της κυκλοφορίας
// SERVO i στις 3 μοίρες
// SERVO j στις 90 μοίρες
// Green Led αναμμένο
// Orange,Red Leds σβηστά
void goGreen() {
  i.write(3);
  delay(200);
  j.write(90);
  // Red Led
  digitalWrite(5, LOW);
  // Orange Led
  digitalWrite(6, LOW);
  // Green Led
  digitalWrite(7, HIGH);
}


// Οι εντολές για διακοπή της κυκλοφορίας
// Το φανάρι γίνεται πορτοκαλί και έπειτα κόκκινο
// Servo i στις 90 μοίρες
// Servo j στις 3 μοίρες
// Έλεγχος για εάν περάσει αντικείμενο από τους αισθητήρες
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
  delay(500);
  i.write(90);
  delay(200);
  j.write(3);
  delay(500);
  // Όσο η τιμή που διαβάζουμε από τους αισθητήρες είναι μικρότερη της τιμής αναφοράς
  // (δεν έχει περάσει αντικείμενο από τους αισθητήρες) τότε περιμένουμε και επαναλαμβάνουμε τον έλεγχο.
  // Η επανάληψη τελειώνει και γίνεται κλήση της διαδικασίας goGreen() όταν περάσει ένα αντικείμενο περάσει
  // και οι τιμές των αισθητήρων γίνουν μεγαλύτερες της τιμής αναφοράς.
  while (analogRead(0) < 1015 && analogRead(1) < 1015) {
    delay(60);
  }
  delay(1500);
  goGreen();
}



void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  // Αντιστοίχιση servo i στο pin 8
  i.attach(8);
  // Αντιστοίχιση servo j στο pin 9
  j.attach(9);
  // Αρχικοποίηση servo i στις 3 μοίρες
  i.write(3);
  delay(200);
  // Αρχικοποίηση servo j στις 90 μοίρες
  j.write(90);
  // Red Led
  digitalWrite(5, LOW);
  // Orange Led
  digitalWrite(6, LOW);
  // Green Led
  digitalWrite(7, HIGH);

}

void loop() {
    // Έλεγχος για την τιμή των αισθητήρων κάθε 60ms .
    // Όταν περάσει ένα αντικείμενο η τιμή που διαβάζουμε από τον αισθητήρα γίνεται μεγαλύτερη της τιμής αναφοράς
    // και εκτελείται η διαδικασία διακοπής της κυκλοφορίας goRed()
    if (analogRead(0) > 1015 || analogRead(1) > 1015) {
      goRed();

    }
    delay(60);

}
const int START_PIN = 13;
const int NUM_PIN = 3;
int current_pin = START_PIN;
bool dir = false; // False if going from green to red; True if going from red to green

void setup() {
  // Setup the pins
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(current_pin, HIGH);

  // Turn off the last pin
  if (dir) {
    digitalWrite(current_pin - 1, LOW);
  } else {
    digitalWrite(current_pin + 1, LOW);
  }
  
  delay(500);

  // Change direction and reset the current pin as needed
  if (current_pin == START_PIN) {
    dir = false;
    current_pin = current_pin - 1;
  } else if (current_pin == START_PIN - NUM_PIN + 1) {
    dir = true;
    current_pin = current_pin + 1;
  } else {
    if (dir) {
      current_pin = current_pin + 1;
    } else {
      current_pin = current_pin - 1;
    }
  }
}

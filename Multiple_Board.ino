const int pirPin1 = 2;  // Connect the output pin of the first PIR sensor to digital pin 2
const int pirPin2 = 3;  // Connect the output pin of the second PIR sensor to digital pin 3
const int buzzerPin = 9; // Connect the positive (longer) leg of the buzzer to digital pin 9
const int ledPin = 10;   // Connect the LED to digital pin 10

volatile int pirState1 = LOW;  // Initialize pirState for the first PIR sensor to LOW
volatile int pirState2 = LOW;  // Initialize pirState for the second PIR sensor to LOW

void setup() {
  Serial.begin(9600);
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Attach interrupts to the PIR sensor pins
  attachInterrupt(digitalPinToInterrupt(pirPin1), motionDetected1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pirPin2), motionDetected2, CHANGE);
}

void loop() {
  // Your main loop code can be empty or handle other tasks
  Serial.println("WELCOME TO INTERRUPT PROGRAM");
  delay(3000);
}

void motionDetected1() {
  pirState1 = digitalRead(pirPin1);

  if (pirState1 == HIGH) {
    Serial.println("PIR1 Motion detected!");

    // Turn on the buzzer when motion is detected by PIR1
    digitalWrite(buzzerPin, HIGH);
    delay(2000); // Buzzer on for 2000 milliseconds (2 seconds)
    digitalWrite(buzzerPin, LOW);
  } else {
    // Turn off the buzzer when no motion is detected
    digitalWrite(buzzerPin, LOW);
  }
}

void motionDetected2() {
  pirState2 = digitalRead(pirPin2);

  if (pirState2 == HIGH) {
    Serial.println("PIR2 Motion detected!");

    // Turn on the LED when motion is detected by PIR2
    digitalWrite(ledPin, HIGH);
    delay(2000); // LED on for 2000 milliseconds (2 seconds)
    digitalWrite(ledPin, LOW);
  } else {
    // Turn off the LED when no motion is detected
    digitalWrite(ledPin, LOW);
  }
}

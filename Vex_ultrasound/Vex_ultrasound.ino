const int outputPin = 9; // Yellow wire (Echo)
const int inputPin = 10;  // Orange wire (Trigger)
const int led = 8;

void setup() {  
  Serial.begin(9600);
  pinMode(outputPin, INPUT);
  pinMode(inputPin, OUTPUT);
}

void loop() {
  digitalWrite(inputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(inputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(inputPin, LOW);

  long duration = pulseIn(outputPin, HIGH);
  long distance = duration / 58; // Conversion to cm
  
  if (distance <= 60) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);
}

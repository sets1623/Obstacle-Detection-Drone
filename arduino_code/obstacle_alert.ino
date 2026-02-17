#define sensorPin 9   // Ultrasonic SIGNAL
#define buzzerPin 8   // Piezo buzzer +
#define ledPin 7      // LED via resistor

long duration;
int distance;

void setup() {
  pinMode(sensorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sensorPin, LOW);

  // Read echo pulse
  pinMode(sensorPin, INPUT);
  duration = pulseIn(sensorPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Alert condition
  if (distance < 50) {          // obstacle detected
    tone(buzzerPin, 1000);      // buzzer sound
    digitalWrite(ledPin, HIGH); // LED ON
  } else {
    noTone(buzzerPin);          // buzzer OFF
    digitalWrite(ledPin, LOW);  // LED OFF
  }

  delay(300);
}

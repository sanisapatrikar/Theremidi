// HC-SR04 Pins
const int trigPin1 = 2; // Pitch sensor
const int echoPin1 = 3;

const int trigPin2 = 4; // Volume sensor
const int echoPin2 = 5;

long duration1, duration2;
float pitchDistance, volumeDistance;

void setup() {
  Serial.begin(9600); // Send data to ESP32
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  return distance;
}

void loop() {
  pitchDistance = getDistance(trigPin1, echoPin1);
  volumeDistance = getDistance(trigPin2, echoPin2);

  // Send data as (pitch,volume)\n
  Serial.print('(');
  Serial.print(pitchDistance, 1); // Round to 1 decimal place
  Serial.print(',');
  Serial.print(volumeDistance, 1);
  Serial.println(')');

  delay(100); // Send every 100ms
}

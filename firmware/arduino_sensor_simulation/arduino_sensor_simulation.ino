#define TRIG_PITCH 2
#define ECHO_PITCH 3
#define TRIG_VOL 4
#define ECHO_VOL 5

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PITCH, OUTPUT);
  pinMode(ECHO_PITCH, INPUT);
  pinMode(TRIG_VOL, OUTPUT);
  pinMode(ECHO_VOL, INPUT);
}

long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 30000); // timeout after 30ms
  if (duration == 0) return 999;
  return duration * 0.034 / 2;
}

void loop() {
  long distPitch = getDistance(TRIG_PITCH, ECHO_PITCH);
  delay(50);  // small delay to avoid cross-talk
  long distVol = getDistance(TRIG_VOL, ECHO_VOL);

  Serial.print("Pitch Distance: ");
  Serial.print(distPitch);
  Serial.print(" cm\tVolume Distance: ");
  Serial.print(distVol);
  Serial.println(" cm");

  delay(300);
}

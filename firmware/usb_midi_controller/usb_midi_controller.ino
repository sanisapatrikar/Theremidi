#include "USB.h"
#include "USB-MIDI.h"

USB_MIDI_ MIDI;

const int trigPin1 = 26;
const int echoPin1 = 25;

const int trigPin2 = 33;
const int echoPin2 = 32;

const int wavetableCC = 16;
const int fmAmountCC = 17;
const byte midiChannel = 1;

const float minDistance = 5.0;
const float maxDistance = 40.0;
const float smoothingFactor = 0.1;

float smoothedWavetableDistance;
float smoothedFmDistance;

void setup() {
  MIDI.begin();
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  smoothedWavetableDistance = getDistance(trigPin1, echoPin1);
  smoothedFmDistance = getDistance(trigPin2, echoPin2);
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 50000);
  float distance = duration * 0.0343 / 2;

  if (distance == 0) {
    return maxDistance;
  }
  return distance;
}

void loop() {
  float rawWavetableDistance = getDistance(trigPin1, echoPin1);
  smoothedWavetableDistance = (smoothingFactor * rawWavetableDistance) + ((1.0 - smoothingFactor) * smoothedWavetableDistance);
  float constrainedWavetable = constrain(smoothedWavetableDistance, minDistance, maxDistance);
  byte wavetableValue = map(constrainedWavetable, minDistance, maxDistance, 127, 0);
  MIDI.sendControlChange(wavetableCC, wavetableValue, midiChannel);

  float rawFmDistance = getDistance(trigPin2, echoPin2);
  smoothedFmDistance = (smoothingFactor * rawFmDistance) + ((1.0 - smoothingFactor) * smoothedFmDistance);
  float constrainedFm = constrain(smoothedFmDistance, minDistance, maxDistance);
  byte fmValue = map(constrainedFm, minDistance, maxDistance, 127, 0);
  MIDI.sendControlChange(fmAmountCC, fmValue, midiChannel);

  MIDI.read();
  delay(20);
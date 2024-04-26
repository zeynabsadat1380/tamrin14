long duration;
int distance;

const int trig = 9;
const int echo = 10;
int ledpin = 5;

void setup() {
  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  distance = calculateDistance();
  if (distance < 10) {
    digitalWrite(ledpin, HIGH);
  }
  else if (distance > 30) {
    digitalWrite(ledpin, LOW);
  }
  else {
    int value = map(distance, 10, 30, 255, 0);
    analogWrite(5, value);
  }
  
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" cm");
}
int calculateDistance() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;
  return distance;
}


#define trig D5
#define echo D6
#define led D7

float tankHeight = 20.0; // cm (adjust based on tank)

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;

  float level = ((tankHeight - distance) / tankHeight) * 100;

  Serial.print("Water Level: ");
  Serial.print(level);
  Serial.println(" %");

  if (level > 90 || level < 10) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  delay(2000);
}
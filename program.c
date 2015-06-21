#define Echo 6
#define Trigger 7

long duration, distance;

int r = 13;
int g = 12;
int b = 11;

void setup() {
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trigger, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  duration = pulseIn(Echo, HIGH);
  distance = (duration/2) / 29;

  if(distance >= 30 || distance <= 0)
  {
    Serial.println("---");
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
  }
  else
  {
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(b, HIGH);
    Serial.print(distance);
    Serial.println("cm");
  }

  if(distance <= 15 && distance >= 1)
  {
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
    Serial.println("Close...");
  }

  delay(400);
  
}

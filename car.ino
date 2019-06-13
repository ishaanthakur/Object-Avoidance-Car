//  Arduino Code  //

const int trigPin = 6;
const int echoPin = 5;
const int echoPin2 = 3;
const int trigPin2 = 10;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop() {
  analogWrite(9, 80);
  analogWrite(11, 80);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.017);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  float duration2 = pulseIn(echoPin2, HIGH);
  float distance2 = (duration2 * 0.017);
  Serial.println(distance2);
  int z = 42;
  //datatable
  int x = 120;
  int y = 600;
  int s1 = 20;
  int s2 = 20;
  if (distance <= s1 && distance2 >= s2) {
    //rigth ->
    analogWrite(9, 0);
    //left <-
    analogWrite(11, x);
    delay(y);
  } else if (distance >= s1 && distance2 >= s2) {
    analogWrite(9, x);
    analogWrite(11, x);
  } else if (distance >= s1 && distance2 <= s2) {
    analogWrite(9, x);
    analogWrite(11, x);
    for (z = 0; z = 42; z++) {
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);
      float duration2 = pulseIn(echoPin2, HIGH);
      float distance2 = (duration2 * 0.017);
      if (distance2 >= s2) {
        delay(550);
        //rigth ->
        analogWrite(9, x);
        //left <-
        analogWrite(11, 0);
        delay(y);

        break;
      } else if (distance2 <= s2) {
        continue;
      }
    }
  } else if (distance <= s1 && distance2 <= s2) {
    //rigth ->
    analogWrite(9, 0);
    //left <-
    analogWrite(11, x);
    delay(y);
  }
}

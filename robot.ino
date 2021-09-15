#define left_forward 3
#define left_backward 2
#define right_forward 5
#define right_backward 4
int value1;
int value2;
#define left_sensor  A0
#define right_sensor  A1

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(left_sensor,INPUT);
  pinMode(right_sensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  value1 = analogRead(left_sensor);
  value2 = analogRead(right_sensor);
  if (value1 > 500 && value2 > 500)
  {
    digitalWrite(left_forward, HIGH);
    digitalWrite(left_backward, HIGH);
    digitalWrite(right_forward, HIGH);
    digitalWrite(right_backward, HIGH);
  }
  else if (value1 > 500 && value2 < 500)
  {
    digitalWrite(left_forward, LOW);
    digitalWrite(left_backward, LOW);
    digitalWrite(right_forward, HIGH);
    digitalWrite(right_backward, HIGH);
  }
  else if (value1 < 500 && value2 > 500)
  {
    digitalWrite(left_forward, HIGH);
    digitalWrite(left_backward, HIGH);
    digitalWrite(right_forward, LOW);
    digitalWrite(right_backward, LOW);
  }
  else
  {
    digitalWrite(left_forward, LOW);
    digitalWrite(left_backward, LOW);
    digitalWrite(right_forward, LOW);
    digitalWrite(right_backward, LOW);
  }
}

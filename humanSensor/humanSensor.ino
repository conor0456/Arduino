const int humanSensor=5;


void setup() 
{
  Serial.begin(9600);
  pinMode(humanSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(humanSensor));
}

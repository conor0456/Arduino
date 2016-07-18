// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int noisePin = 4;

double startDistance=9999;
double accuracy=.05;

void setup() 
{
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  startDistance=(getDistance()+getDistance())/2;
  Serial.print("Start distance: ");
  Serial.print(startDistance);
  Serial.println();
  delay(500);
}

void loop() 
{
  double dist=getDistance();
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println();
  if(dist<startDistance-(accuracy*startDistance))
  {
    triggered();
    Serial.println("INTRUDER");
  }
  
}

double getDistance()
{
  delay(50);
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  if(duration*0.034/2>startDistance&&startDistance!=9999)
  {
    return startDistance;
  }
  return duration*0.034/2;
  
}

void triggered()
{
  for(int i=0; i<5; i++)
  {
    tone(noisePin,1000,300);
    delay(300);
  }
  
}



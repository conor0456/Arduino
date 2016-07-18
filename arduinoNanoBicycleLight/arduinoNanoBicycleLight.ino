// nrf24_client
const int L1=12;
const int L2=13;
int t=50;

void setup() 
{
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
}


void loop()
{
  digitalWrite(L1,HIGH);
  delay(t);
  digitalWrite(L1,LOW); 
  delay(t);
  digitalWrite(L2,HIGH);
  delay(t);
  digitalWrite(L2,LOW);
  delay(t);
}

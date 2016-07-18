int lightPin = 0;  //define a pin for Photo resistor
int noisePin=4;     //define a pin for LED
int ledPin=7;

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( noisePin, OUTPUT );
    pinMode(ledPin,OUTPUT);
}

void loop()
{
    int light=analogRead(lightPin);
    Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
      //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(10); //short delay for faster response to light.
   if(light<600)
   {
    tone(noisePin,1000,500);
    digitalWrite(ledPin,HIGH);
   }
   else
   {
    digitalWrite(ledPin,LOW);
   }

}

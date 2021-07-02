// C++ code
//
int ledPin = 6;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  //Fading the LED
  for(int i=0; i<255; i++){
    analogWrite(ledPin, i);
    delay(5);
  }
  for(int i=255; i>0; i--){
    analogWrite(ledPin, i);
    delay(5);
  }
}

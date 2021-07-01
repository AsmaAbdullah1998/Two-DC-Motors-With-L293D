#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to

#define NUMPIXELS      6 // number of neopixels in Ring
#include <avr/power.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int delayval = 100; // timing delay

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int A = 8;
int B = 9;
int C = 7;
int D = 13;
int E = 12;
int F = 10;
int G = 11;

char segment[] = {A, B, C, D, E, F, G};
//functions 

void setup()
{
  for(int i = 0; i<7; i++){
    pinMode(segment[i], OUTPUT);
  }
  
  
   pixels.begin(); // Initializes the NeoPixel library.
//  Serial.begin(9600);
  
  

}

void loop(){
  
  //zero
  digitalWrite(G, HIGH);
  delay(1000);
  
  setColor();
  
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    
    // Serial.println(i);
    
    if (i == NUMPIXELS){
    	i = 0; // start all over again!
        setColor();
	  }

  }
}

void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
  Serial.print("red: ");
  Serial.println(redColor);
  Serial.print("green: ");
  Serial.println(greenColor);
  Serial.print("blue: ");
  Serial.println(blueColor);
  
}

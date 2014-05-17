/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int red = 13;
int blue = 12;
int green = 11;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the LEDS.
  pinMode(red, OUTPUT);  
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  
  Serial.begin(9600);
    
    

}

// the loop routine runs over and over again forever:
void loop() {
  int brightpot = analogRead(A3);
  float luminosity = brightpot * (255 / 1023.0);
  int redpot = analogRead(A0);
  float redbright = redpot * (luminosity / 1023.0);
  int greenpot = analogRead(A1);
  float greenbright = greenpot * (luminosity / 1023.0);
  int bluepot = analogRead(A2);
  float bluebright = bluepot * (luminosity / 1023.0);
 
  analogWrite(green, greenbright);   // turn the LED on (HIGH is the voltage level)
  analogWrite(red, redbright);   // turn the LED on (HIGH is the voltage level)
  analogWrite(blue, bluebright);   // turn the LED on (HIGH is the voltage level)
  // delay(1000);               // wait for a second
  // analogWrite(green, 000);    // turn the LED off by making the voltage LOW
 // analogWrite(red, 000);    // turn the LED off by making the voltage LOW
  //analogWrite(blue, 000);    // turn the LED off by making the voltage LOW
 // delay(1000);               // wait for a second
  
  
  
    // read the input on analog pin 0:
 
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

  // print out the value you read:
  Serial.println(luminosity);

}

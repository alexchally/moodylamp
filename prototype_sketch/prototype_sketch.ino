/*
  This code is for adjusting the color and brightness of an RGB LED with three potentiometers, thee for R, G and B, and one for luminosity. 
 Written By Alex Chally 
 For License see www.github.com/alexchally/moodylamp
 */
//Declaring some variables, you know, because.
int red_led = 13;
int blue_led = 12;
int green_led = 11;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the LEDS.
  pinMode(red_led, OUTPUT);  
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);

  //starting a serial connection just to help debug 
  Serial.begin(9600);
}

void loop() {
  // read all the analog values for the R G B pots 
  int red_pot = analogRead(A0);
  int green_pot = analogRead(A1);
  int blue_pot = analogRead(A2);
  int bright_pot = analogRead(A3);

  // converts the brightness pot to a value from 0 to red255. 
  float luminosity = bright_pot* (255 /1023.0); // converts the ADC from 0-1023 to 0-255, the proper range for PWM 

  // adjust the brightness with respect to the luminosity pot
  float red = (red_pot/1023.0)*(luminosity);
  float green = (green_pot/1023.0) * (luminosity);
  float blue = (blue_pot/1023.0) * (luminosity);

  //Sets the values for the LEDs
  analogWrite(red_led, red);   
  analogWrite(green_led, green);   
  analogWrite(blue_led, blue);  


  // Used for debugging a value:
  Serial.println(luminosity);
  // Serial.println(red_pot);

}


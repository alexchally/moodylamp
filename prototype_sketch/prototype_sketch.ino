/*
  This code is for adjusting the color and brightness of an RGB LED with three potentiometers, thee for R, G and B, and one for luminosity. 
 Written By Alex Chally 
 For License see www.github.com/alexchally/moodylamp
 */
//Declaring some variables, you know, because.
int red_led = 13;
int blue_led = 12;
int green_led = 11;
int power = 52;
int bias = 5;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the LEDs and power switch
  pinMode(red_led, OUTPUT);  
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);  
  pinMode(power, INPUT);
  
  //starting a serial connection just to help debug 
  Serial.begin(9600);
}

void loop() {
    
// read the power switch to see if the lights should be on
  int power_switch = digitalRead(power);
    
  if (power_switch == 1)
    {
   // read all the analog values for the R G B pots 
    int red_pot = analogRead(A0);
    int green_pot = analogRead(A1);
    int blue_pot = analogRead(A2);
    int bright_pot = analogRead(A3);
. // converts the ADC from 0-1023 to 0-250, the proper range for PWM when bias is factored in 
    float luminosity = (bright_pot/1023.0) * 250;  

  // adjust the brightness with respect to the luminosity pot. The bias value is to keep the lights from flickering when they get too low.
    float red = ((red_pot/1023.0) * (luminosity)) + bias;
    float green = (green_pot/1023.0) * (luminosity) + bias;
    float blue = (blue_pot/1023.0) * (luminosity) + bias;

  //Sets the values for the LEDs
    analogWrite(red_led, red);   
    analogWrite(green_led, green);   
    analogWrite(blue_led, blue); 
    
    }
   else
    {
     analogWrite(red_led, 0);   
     analogWrite(green_led, 0);   
     analogWrite(blue_led, 0);  
     
   }
  // Used for debugging a value:
  Serial.println(power_switch);
  // Serial.println(red_pot);

}


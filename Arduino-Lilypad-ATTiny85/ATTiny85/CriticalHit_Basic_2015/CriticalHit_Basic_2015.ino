/*Code for the basic attiny45/85 microcontroller with fade and blink functionalities
 */
//                        attiny45/85
//                   reset -+---+- power
//  (always blinking) pb3 -+*  +- pb2 (toggled by switch)
//       (touch input) pb4 -+   +- pb1 (fading toggled by switch)
//                  ground -+---+- pb0 (fading always)

int fadeAlways = 0; // the led that fades on and off
int fadeToggle = 1; // the led that toggles fading on and off
int toggle = 2; // the led that's toggled by the switch
int blinking = 3; // the led that's blinking

int fadeVal = 0, fadestep = 5;
int fadeState = LOW;
int togglestate = LOW;
int blinkCounter = 0;
int blinkStep = LOW;


void setup() {
  pinMode(fadeAlways, OUTPUT);  
  pinMode(fadeToggle, OUTPUT);  
  pinMode(toggle, OUTPUT); 
  pinMode(blinking, OUTPUT);  

  pinMode(4, INPUT);   // switch pin
  digitalWrite(4, HIGH);  // turn on pull-up resistor
}

void loop() {
  int switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open
  if (switchValue==0)
  {
    int switchDebounce = digitalRead(4);
    while (switchDebounce == 0)
    {
      switchDebounce = digitalRead(4);
    }
  }
  delay(1);
  //pin 0: fade always
  analogWrite(fadeAlways, fadeVal);

  fadeVal = fadeVal + fadestep;
  if (fadeVal == 255) fadestep = -5;
  if (fadeVal == 0) fadestep = 5;

  //pin 1: toggles fading
  if (switchValue == 0) {
    if (fadeState == LOW){
      fadeState = HIGH;
    }
    else 
    {
      fadeState = LOW;
    }
  }

  if (fadeState == LOW)
  {
    analogWrite(fadeToggle, 0);
  }
  else
  {
    analogWrite(fadeToggle, fadeVal);
  }

  //pin 2: toggles on and off
  if (switchValue == 0) {
    if (togglestate == LOW) togglestate = HIGH;
    else togglestate = LOW;

    digitalWrite(toggle, togglestate);
  }

  //pin 3: on when touching
  blinkCounter = blinkCounter + blinkStep;
  if (blinkCounter == 40) blinkStep = -1;
  if (blinkCounter == 0) blinkStep = 1;
  
  if (blinkCounter > 20 )
  {
    digitalWrite(blinking, LOW);
  }
  else
  {
    digitalWrite(blinking, HIGH);
  }
}

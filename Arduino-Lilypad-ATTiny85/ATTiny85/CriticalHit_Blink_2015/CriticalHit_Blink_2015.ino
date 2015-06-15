/*Code for the blink attiny45/85 chip in which pins blink in sequence
 */
//                        attiny45/85
//                   reset -+---+- power
//           (blink 4) pb3 -+*  +- pb2 (blink 3)
//       (touch input) pb4 -+   +- pb1 (blink 2)
//                  ground -+---+- pb0 (blink 1)
//               
//                on touch blink speeds up

int blink1 = 0; 
int blink2 = 1; 
int blink3 = 2; 
int blink4 = 3; 

int blinkSpeed = 50;
int switchValue;

void setup() {
  pinMode(blink1, OUTPUT);  
  pinMode(blink2, OUTPUT);  
  pinMode(blink3, OUTPUT); 
  pinMode(blink4, OUTPUT);  

  pinMode(4, INPUT);   // switch pin
  digitalWrite(4, HIGH);  // turn on pull-up resistor
}

void loop() {  
switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open
  
if (switchValue == 0)
{
  blinkSpeed = 100;
}
else
{
  blinkSpeed = 250;
}
digitalWrite(blink1, HIGH);
digitalWrite(blink2, LOW);
digitalWrite(blink3, LOW);
digitalWrite(blink4, LOW);
delay(blinkSpeed);

switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open
  
if (switchValue == 0)
{
  blinkSpeed = 100;
}
else
{
  blinkSpeed = 250;
}

digitalWrite(blink1, LOW);
digitalWrite(blink2, HIGH);
digitalWrite(blink3, LOW);
digitalWrite(blink4, LOW);
delay(blinkSpeed);

switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open
  
if (switchValue == 0)
{
  blinkSpeed = 100;
}
else
{
  blinkSpeed = 250;
}

digitalWrite(blink1, LOW);
digitalWrite(blink2, LOW);
digitalWrite(blink3, HIGH);
digitalWrite(blink4, LOW);
delay(blinkSpeed);

switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open
  
if (switchValue == 0)
{
  blinkSpeed = 100;
}
else
{
  blinkSpeed = 250;
}

digitalWrite(blink1, LOW);
digitalWrite(blink2, LOW);
digitalWrite(blink3, LOW);
digitalWrite(blink4, HIGH);
delay(blinkSpeed);
}

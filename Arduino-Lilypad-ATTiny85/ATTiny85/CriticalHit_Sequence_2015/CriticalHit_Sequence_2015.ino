/*Code for the sequence attiny45/85 chip  in which pins toggle on in sequence
 * when the switch is pressed.
 */
//                          attiny45/85
//                    reset -+---+- power
//           (toggle 4) pb3 -+*  +- pb2 (toggle 3)
//       (switch input) pb4 -+   +- pb1 (toggle 2)
//                   ground -+---+- pb0 (toggle 1)
//               
//                on toggles to the next pin

int ledNumber= 0;


void setup() {
  pinMode(0, OUTPUT);  
  pinMode(1, OUTPUT);  
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);  

  pinMode(4, INPUT);   // switch pin
  digitalWrite(4, HIGH);  // turn on pull-up resistor
  
  digitalWrite(0, HIGH); // start with light 1 on
}

void loop() {  
  int switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open
  if (switchValue==0)
  {
    int switchDebounce = digitalRead(4);
    while (switchDebounce == 0)
    {
      switchDebounce = digitalRead(4);
      delay(1);
    }
  }

  if (switchValue == 0)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(ledNumber, HIGH);

    ledNumber++;

    if (ledNumber== 4)
    {
      ledNumber = 0;
    }
  }
}

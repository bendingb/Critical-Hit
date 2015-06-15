/*Code for the fading attiny45/85 in which pins fade in sequence.  
 * When switch is pressed, all pins fade together.
 */
//                        attiny45/85
//                   reset -+---+- power
//            (fade 4) pb3 -+*  +- pb2 (fade 3)
//      (switch input) pb4 -+   +- pb1 (fade 2)
//                  ground -+---+- pb0 (fade 1)
//               
//               Ppins fade in sequence.  When switch is pressed, all pins fade on and off 

void setup() {                
  pinMode(0, OUTPUT);  
  pinMode(1, OUTPUT);  
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);  

  pinMode(4, INPUT);   // switch pin
  digitalWrite(4, HIGH);  // turn on pull-up resistor
}

void loop() {
  for (int k = 0; k<4;k++)
  {
    for (int i = 1; i<1000; i=i+10)
    {
      int switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open
      if (switchValue == 0)
      {
        digitalWrite(0, HIGH); 
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
      }
      digitalWrite(k, HIGH); 
      delayMicroseconds(i);  
      if (switchValue == 0)      
      {
        digitalWrite(0, LOW); 
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
      }
      digitalWrite(k, LOW);    
      delayMicroseconds(1000-i);   

    }  
    for (int i = 1; i<1000; i=i+10)
    {
      int switchValue = digitalRead(4); // read the switch.  0 if closed, 1 if open
      if (switchValue == 0)
      {
        digitalWrite(0, HIGH); 
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
      }
      digitalWrite(k, HIGH); 
      delayMicroseconds(1000-i);   
      if (switchValue == 0)      
      {
        digitalWrite(0, LOW); 
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
      }      
      digitalWrite(k, LOW);   
      delayMicroseconds(i);         
    } 
    delay(200);
  }  
}

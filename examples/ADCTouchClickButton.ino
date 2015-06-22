#include <ADCTouchClickButton.h>

ADCTouchClickButton button1(A0, 10, 250, LOW);
    
void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  button1.debounceTime = 20;   // Debounce timer in ms
  button1.multiclickTime = 250;  // Time limit for multi clicks
  button1.longClickTime = 1000; // time until "held-down clicks" register
  button1.createReference(100);
}

void loop() {
  button1.Update();
  if (button1.clicks == 1) {
     Serial.println("Single");
  }
  if (button1.clicks == 2) {
     Serial.println("Double");
  }
   if (button1.clicks == 3) {
     Serial.println("3 Double");
  }  
  if (button1.clicks == 4) {
     Serial.println("4 Double");
  } 
  if (button1.clicks == -3) {
     Serial.println("3 long");
  }  
  if (button1.clicks == -1) {
    Serial.println("long");
  }  
  delay(50);
}

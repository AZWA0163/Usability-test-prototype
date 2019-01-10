#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define RING1_PIN 6
#define RING2_PIN 7
#define BUTTON_PIN 3
#define RING1_NUMBER 16
#define RING2_NUMBER 16

Adafruit_NeoPixel RING1 = Adafruit_NeoPixel(RING1_NUMBER, RING1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel RING2 = Adafruit_NeoPixel(RING2_NUMBER, RING2_PIN, NEO_GRB + NEO_KHZ800);

int fade, i, j, PHASE, x;
bool oldState, newState;
int showType = 0;

void setup() {
  pinMode (BUTTON_PIN, INPUT_PULLUP);
  RING1.begin();
  RING1.show();
  RING2.begin();
  RING2.show();
}

void loop() {
  // Get current button state.
  bool newState = digitalRead(BUTTON_PIN);

  // Check if state changed from high to low (button press).
  if (newState == LOW && oldState == HIGH) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    if (newState == LOW) {
      showType++;
      if (showType > 10)
        showType=0;
      startShow(showType);
    }
  }
  // Set the last button state to the old state.
  oldState = newState;
}

void startShow(int PHASE) {
  switch(PHASE){
    case 0: off();
            break;
    case 1: bond_o_meter_high();
            break;
    case 2: planning();
            break;
    case 3: agreement();
            break;
    case 4: pointing();
            break;
    case 5: charging_family();
            break;
    case 6: bond_o_meter_low();
            break;
    case 7: radar();
            break;
    case 8: chores();
            break;
    case 9: charging_chores();
            break;
    case 10: bond_o_meter_high();
            break;
  }
}

void off(){
  for(i = 0; i < (RING1_NUMBER); i++) 
  {
    RING1.setPixelColor(i, 0, 0, 0);
    RING1.show();
    RING2.setPixelColor(i, 0, 0, 0);
    RING2.show();
  }
}

void bond_o_meter_low(){
  for(i = 0; i < (RING1_NUMBER); i++) 
  {
    RING1.setPixelColor(i, 40, 40, 40);
    RING1.show();
    RING2.setPixelColor(i, 40, 40, 40);
    RING2.show();
  }
}

void bond_o_meter_high(){
  for(i = 0; i < (RING1_NUMBER); i++) 
  {
    RING1.setPixelColor(i, 255, 255, 255);
    RING1.show();
    RING2.setPixelColor(i, 255, 255, 255);
    RING2.show();
  }
}

void planning(){
  for(i = 0; i < (RING1_NUMBER); i++) 
  {
    RING1.setPixelColor(i, 255, 130, 0);
    RING1.show();
    RING2.setPixelColor(i, 55, 55, 55);
    RING2.show();
  }
}

void agreement(){
  for( i = 0; i < (RING1_NUMBER); i++) 
  {
    RING1.setPixelColor(i, 255, 130, 0);
    RING1.show();
  }  
  for(j = 0; j < RING2_NUMBER; j++){
    RING2.setPixelColor(j, 255, 130, 0);
    RING2.show();
  }
}

void pointing(){
  for(i = 0; i < (RING1_NUMBER); i++){
    RING1.setPixelColor(i, 10, 10, 8);
    RING1.setPixelColor(12, 255, 130, 0);
    RING1.show();
    RING2.setPixelColor(i, 10, 10, 8);
    RING2.setPixelColor(4, 255, 130, 0);
    RING2.show();
  } 
}

/* Pulse Animation
void pointing() {
  for(i = 0; i < (RING1_NUMBER - 3); i++){
    RING1.setPixelColor(i, 10, 10, 8);
    RING1.setPixelColor((RING1_NUMBER - 2), 255, 130, 0);
    RING1.show();
    RING2.setPixelColor(i, 10, 10, 8);
    RING2.setPixelColor((RING2_NUMBER - 2), 255, 130, 0);
    RING2.show();
  }
  for(j = 0; j < 3; j++){
    for(fade = 10; fade <= 255; fade+=10){
      RING1.setPixelColor((RING1_NUMBER - 3), fade, map(fade, 0, 255, 0, 130), 10);
      RING1.setPixelColor((RING1_NUMBER - 1), fade, map(fade, 0, 255, 0, 130), 10);
      delay(25);
      RING1.show();
      RING2.setPixelColor((RING2_NUMBER - 3), fade, map(fade, 0, 255, 0, 130), 10);
      RING2.setPixelColor((RING2_NUMBER - 1), fade, map(fade, 0, 255, 0, 130), 10);
      delay(25);
      RING2.show();
    }
      for(fade = 250; fade >= 10; fade-=10){
      RING1.setPixelColor((RING1_NUMBER - 3), fade, map(fade, 0, 255, 0, 130), 10);
      RING1.setPixelColor((RING1_NUMBER - 1), fade, map(fade, 0, 255, 0, 130), 10);
      delay(25);
      RING1.show();
      RING2.setPixelColor((RING2_NUMBER - 3), fade, map(fade, 0, 255, 0, 130), 10);
      RING2.setPixelColor((RING2_NUMBER - 1), fade, map(fade, 0, 255, 0, 130), 10);
      delay(25);
      RING2.show();
    }
  }
}
*/
void charging_family(){
  for(j = 0; j < 3; j++){
    for(fade = 10; fade <= 255; fade+=10){ 
      for(i = 0; i < (RING1_NUMBER); i++){
        RING1.setPixelColor(i, fade, map(fade, 0, 255, 0, 130), 0);
      }
      for(i = 0; i < (RING1_NUMBER); i++){
        RING2.setPixelColor(i, fade, map(fade, 0, 255, 0, 130), 0);
      }
      delay(25);
      RING1.show();
      RING2.show();
    }
    for(fade = 250; fade >= 0; fade-=10){ 
      for(i = 0; i < (RING1_NUMBER); i++){
        RING1.setPixelColor(i, fade, map(fade, 0, 255, 0, 130), 0);
      }
      for(i = 0; i < (RING2_NUMBER); i++){
        RING2.setPixelColor(i, fade, map(fade, 0, 255, 0, 130), 0);
      }
      delay(25);
      RING1.show();
      RING2.show();
    }
  }
}

void chores(){
  for(i = 0; i < (RING1_NUMBER - 1); i++){
    RING2.setPixelColor(i, 0, 0, 0);
    RING2.setPixelColor(2, 255, 130, 0);
    RING2.setPixelColor(10, 255, 130, 0);
    RING2.setPixelColor(8, 0, 0, 255);
    RING2.show();
    RING1.setPixelColor(i, 0, 0, 0);
    RING1.show();
  }
}

void radar(){
  for(i = 0; i < (RING1_NUMBER); i++){
    RING2.setPixelColor(i, 0, 0, 0);
    RING2.setPixelColor(2, 255, 130, 0);
    RING2.setPixelColor(10, 255, 130, 0);
    RING2.show();
    RING1.setPixelColor(i, 0, 0, 0);
    RING1.show();
  } 
}

void charging_chores(){
  for(j = 0; j < 3; j++){
    for(fade = 10; fade <= 255; fade+=10){ 
      for(i = 0; i < (RING1_NUMBER); i++){
        RING1.setPixelColor(i, 0, 0, 0);
      }
      for(i = 0; i < (RING1_NUMBER); i++){
        RING2.setPixelColor(i, 0, 0, fade);
      }
      delay(25);
      RING1.show();
      RING2.show();
    }
    for(fade = 250; fade >= 0; fade-=10){ 
      for(i = 0; i < (RING1_NUMBER); i++){
        RING1.setPixelColor(i, 0, 0, 0);
      }
      for(i = 0; i < (RING2_NUMBER); i++){
        RING2.setPixelColor(i, 0, 0, fade);
      }
      delay(25);
      RING1.show();
      RING2.show();
    }
  }
}


/*
 * LightControl.ino
 * by Jon Polfer
 * 7/22/2017 for the Milwaukee Hack-N-Tell
 * This code will turn on/off an Etekcity Zap RF-controlled outlet using 
 * an infrared remote control.
 */

#define ZAP_OUTLETS_PULSE_LENGTH  189
#define IR_DATA_RECV_PIN  2
#define RF_DATA_XMIT_PIN  10
#define IR_STAR_CODE      0x40BF48B7
#define IR_CIRCLE_CODE    0x40BFBA45
#define OUTLET_1_ON_CODE  4543795
#define OUTLET_1_OFF_CODE 4543804

// IRLib2 includes/setup
#include <IRLibDecodeBase.h> // First include the decode base
#include <IRLib_P01_NEC.h>   // Now include only the protocols you wish
//#include <IRLib_P02_Sony.h>  // to actually use. The lowest numbered
//#include <IRLib_P07_NECx.h>  // must be first but others can be any order.
//#include <IRLib_P09_GICable.h>
//#include <IRLib_P11_RCMM.h>
#include <IRLibCombo.h>     // After all protocols, include this
// All of the above automatically creates a universal decoder
// class called "IRdecode" containing only the protocols you want.
// Now declare an instance of that decoder.
IRdecode myDecoder;
// Include a receiver either this or IRLibRecvPCI or IRLibRecvLoop
#include <IRLibRecv.h> 
IRrecv myReceiver(IR_DATA_RECV_PIN);  //pin number for the receiver


// RCSwitch includes/setup
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

void setup() {
  // Serial setup
  Serial.begin(9600);
  delay(2000); 
  while (!Serial); //delay for Leonardo
  
  // RC Switch setup
  mySwitch.enableTransmit(RF_DATA_XMIT_PIN);  // Using Pin #10
  mySwitch.setPulseLength(ZAP_OUTLETS_PULSE_LENGTH); // IMPORTANT!  Needed for RF to work!

  // IRLib2 setup
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
}

void loop() 
{
    if (myReceiver.getResults()) 
    { 
      myDecoder.decode();
      if(myDecoder.value == IR_STAR_CODE) // Received start
      {
        Serial.println(F("Received ON button press!"));
        mySwitch.send(OUTLET_1_ON_CODE, 24); // outlet 1 on
      } 
      if(myDecoder.value == IR_CIRCLE_CODE)
      {
        Serial.println(F("Received OFF button press!"));
        mySwitch.send(OUTLET_1_OFF_CODE, 24); // outlet 1 off
      }
      myReceiver.enableIRIn();      //Restart receiver
    }
}

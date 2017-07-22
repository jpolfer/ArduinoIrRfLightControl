#include <RCSwitch.h>

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
IRrecv myReceiver(2);  //pin number for the receiver
RCSwitch mySwitch = RCSwitch();

void setup() {
  // RC Switch setup
  mySwitch.enableTransmit(10);  // Using Pin #10
  mySwitch.setPulseLength(189); // IMPORTANT!  Needed for RF to work!

  // IRLib2 setup
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
}

void loop() {
    if (myReceiver.getResults()) { 
    myDecoder.decode();           //Decode it
    if(myDecoder.value == 0x40BF48B7) // Received start
    {
      mySwitch.send(4543795, 24); // outlet 1 on
    }
    if(myDecoder.value == 0x40BFBA45) // Received start
    {
      mySwitch.send(4543804, 24); // outlet 1 off
    }
    myReceiver.enableIRIn();      //Restart receiver
  }
  /*
  mySwitch.send(4543795, 24); // outlet 1 on
  delay(2000);
  mySwitch.send(4543804, 24); // outlet 1 off
  delay(2000);
  */
}

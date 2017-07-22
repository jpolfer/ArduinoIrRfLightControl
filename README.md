
# ArduinoIrRfLightControl
Sketches to turn on/off Etekcity RF power outlets using IR remote codes

# Important Links
- http://arduinobasics.blogspot.com/2014/06/433-mhz-rf-module-with-arduino-tutorial.html - Tutorial on using the FS1000A transmitter, MX-RM-5V receiver
- https://arduino-info.wikispaces.com/file/view/IR-Receiver-AX-1838HS.pdf - Datasheet for the IR receiver I bought

# Notes
### RF Code table for Etekcity Remote

| Button / Outlet | ON code                        | OFF code                     |
|-----------------|--------------------------------|------------------------------|
| 1               | 4543795 / 24bit Protocol: 1    | 4543804 / 24bit Protocol: 1  |
| 2               | 4543939 / 24bit Protocol: 1    | 4543948 / 24bit Protocol: 1  |
| 3               | 4544259 / 24bit Protocol: 1    | 4544268 / 24bit Protocol: 1  |

#### To determine the codes for your Etekcity outlets:
1.  Hookup the MX-RM-5V RF receiver to your Arduino (Vcc to 5V, GND to GND, pin next to Vcc is recieve data - set to pin D2)
1.  Upload the RCSwitch example program ReceiveDemo_Simple to your Arduino using Arduino IDE.
1.  Turn on the serial monitor program from the Arduino IDE.
1.  Push the buttons on your remote and record what the codes are that the buttons emit.


*IMPORTANT*: When sending codes via the XY-FST transmitter, MUST call setPulseLength(189) on the RCSwitch object to set the pulse length for transmit to work!


### IR Code dump from IRLib2

Star button (F1 from work 4k monitor)

```
Decoded NEC(1): Value:40BF48B7 Adrs:0 (32 bits) 
Raw samples(68): Gap:7442
  Head: m8962  s4478
0:m558 s582	1:m550 s1702		 2:m550 s586	3:m550 s582		 
4:m554 s582	5:m550 s582		 6:m554 s582	7:m550 s586		 
8:m550 s1698	9:m554 s582		 10:m554 s1698	11:m554 s1698		 
12:m554 s1698	13:m554 s1698		 14:m554 s1698	15:m554 s1698		 

16:m554 s582	17:m550 s1702		 18:m554 s582	19:m550 s586		 
20:m550 s1698	21:m554 s582		 22:m554 s582	23:m550 s586		 
24:m546 s1702	25:m550 s586		 26:m550 s1698	27:m554 s1702		 
28:m550 s586	29:m550 s1702		 30:m550 s1702	31:m554 s1698		 

32:m550
Extent=68182
Mark  min:546	 max:558
Space min:582	 max:1702
```

Circle button (F2 from work 4k monitor)

```
Decoded NEC(1): Value:40BFBA45 Adrs:0 (32 bits) 
Raw samples(68): Gap:40150
  Head: m8766  s4554
0:m510 s622	1:m506 s1742		 2:m510 s622	3:m482 s650		 
4:m506 s622	5:m506 s626		 6:m506 s622	7:m510 s622		 
8:m506 s1738	9:m514 s622		 10:m506 s1738	11:m510 s1742		 
12:m510 s1738	13:m510 s1742		 14:m510 s1738	15:m514 s1738		 

16:m514 s1734	17:m518 s614		 18:m510 s1738	19:m514 s1738		 
20:m510 s1738	21:m510 s622		 22:m510 s1738	23:m510 s622		 
24:m510 s618	25:m510 s1742		 26:m510 s622	27:m506 s622		 
28:m510 s622	29:m506 s1742		 30:m510 s622	31:m506 s1742		 

32:m510
Extent=67910
Mark  min:482	 max:518
Space min:614	 max:1742
```
#### To determine the IR codes from your remote:

1.  Hookup an IR receiver IC to your Arduino (set data out to pin D2)
1.  Upload the IRLib2 comboDump example program to your Arduino.
1.  Turn on the serial monitor program from the Arduino IDE.
1.  Push the buttons on your remote and record what the codes are that the buttons emit.



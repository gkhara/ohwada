// 2012-06-10 PIC24FJ64GB002

/********************************************************************
 FileName:     	PIC24FJ64GB002_PIM.h
 Dependencies:  See INCLUDES section
 Processor:     PIC24FJ64GB002
 Hardware:      PIC24FJ64GB002 PIM
 Compiler:      Microchip C30
 Company:       Microchip Technology, Inc.

 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the ?Company?) for its PIC? Microcontroller is intended and
 supplied to you, the Company?s customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN ?AS IS? CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************************
 File Description:

 Change History:
  Rev   Date         Description
        2012-06-10   Initial support for PIC24FJ64GB002 family
********************************************************************/

#ifndef HARDWARE_PROFILE_PIC24FJ64GB002_PIM_H
#define HARDWARE_PROFILE_PIC24FJ64GB002_PIM_H

#include <p24FJ64GB002.h>
#include <ports.h>
#include <uart2.h>

    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/
    /******** Application specific definitions *************************/
    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/

    /** Board definition ***********************************************/
    //These defintions will tell the main() function which board is
    //  currently selected.  This will allow the application to add
    //  the correct configuration bits as wells use the correct
    //  initialization functions for the board.  These defitions are only
    //  required in the stack provided demos.  They are not required in
    //  final application design.

    #define DEMO_BOARD PIC24FJ64GB002_PIM
    #define EXPLORER_16
    #define PIC24FJ64GB002_PIM
    #define CLOCK_FREQ 32000000
    #define DEMO_BOARD_NAME_STRING "PIC24FJ64GB002 PIM"
        
    /** LED ************************************************************/ 
    // set output RB15, 14, 13, 9, 5, 4, 3, 2 
    #define InitAllLEDs()      LATB &= 0x1DC3; TRISB &= 0x1DC3;
      
    #define mLED_1            LATBbits.LATB2
    #define mLED_2            LATBbits.LATB3
    #define mLED_3            LATBbits.LATB4
    #define mLED_4            LATBbits.LATB5
    #define mLED_5            LATBbits.LATB9
    #define mLED_6            LATBbits.LATB13
    #define mLED_7            LATBbits.LATB14
    #define mLED_8            LATBbits.LATB15
         
    #define LED0_On()         mLED_1 = 1;
    #define LED1_On()         mLED_2 = 1;
    #define LED2_On()         mLED_3 = 1;
    #define LED3_On()         mLED_4 = 1;
    #define LED4_On()         mLED_5 = 1;
    #define LED5_On()         mLED_6 = 1;
    #define LED6_On()         mLED_7 = 1;
    #define LED7_On()         mLED_8 = 1;
    
    #define LED0_Off()        mLED_1 = 0;
    #define LED1_Off()        mLED_2 = 0;
    #define LED2_Off()        mLED_3 = 0;
    #define LED3_Off()        mLED_4 = 0;
    #define LED4_Off()         mLED_5 = 0;
    #define LED5_Off()         mLED_6 = 0;
    #define LED6_Off()         mLED_7 = 0;
    #define LED7_Off()         mLED_8 = 0;
       
    /** SWITCH *********************************************************/
    // set input RA4, 3, 2, 1
    #define mInitSwitch1()      TRISAbits.TRISA1=1; AD1PCFGLbits.PCFG1 = 1; 
    #define mInitSwitch2()      TRISAbits.TRISA2=1;
    #define mInitSwitch3()      TRISAbits.TRISA3=1;
    #define mInitSwitch4()      TRISAbits.TRISA4=1;
    #define InitAllSwitches()    mInitSwitch1(); mInitSwitch2(); mInitSwitch3(); mInitSwitch4();

    #define Switch1Pressed()    ((PORTAbits.RA1  == 0)? TRUE : FALSE)
    #define Switch2Pressed()    ((PORTAbits.RA2  == 0)? TRUE : FALSE)
    #define Switch3Pressed()    ((PORTAbits.RA3  == 0)? TRUE : FALSE)
    #define Switch4Pressed()    ((PORTAbits.RA4  == 0)? TRUE : FALSE)

    /** POT ************************************************************/
    // AD1PCFG PCFG0 : AN0
    // AD1CON2 VCFG : VR+ = AVdd VR- = AVss
    // AD1CON3 ADCS : 128 Tcv
    // AD1CON1 SSRC : SAMP
    // AD1CON3 SAMC : 1 Tad
    // AD1CON1 FORM : integer
    // AD1CON2 SMPI : 1st sample
    // AD1CON1 ADON : enable AD
    #define mInitPOT()  {AD1PCFGLbits.PCFG0 = 0;    AD1CON2bits.VCFG = 0x0;    AD1CON3bits.ADCS = 0xFF;    AD1CON1bits.SSRC = 0x0;    AD1CON3bits.SAMC = 0b10001;    AD1CON1bits.FORM = 0b00;    AD1CON2bits.SMPI = 0x0;    AD1CON1bits.ADON = 1;}

    // MUXA uses AN0
    // CH0NB = VR- , CH0SB = AN0  
    // CH0NA = VR- , CH0SA = AN0
    #define SelectPotCh()		AD1CHS = 0x0;
            
    /** I/O pin definitions ********************************************/
    #define INPUT_PIN 1
    #define OUTPUT_PIN 0

    /** UART ********************************************/ 
    #define BAUDRATE2	57600
    #define BRG_DIV2		4
    #define BRGH2			1
    #define DEMO_TIMEOUT_LIMIT  0xF000

    #define GetSystemClock()            32000000UL
    #define GetPeripheralClock()        (GetSystemClock())
    #define GetInstructionClock()       (GetSystemClock() / 2)

    // set U2RX on pin 17 (RP8),  set U2TX on pin 16 (RP7)
    #define InitUartPort()	RPINR19bits.U2RXR = 8; RPOR3bits.RP7R = 5;

    /** Debug print interface ******************************************/
    #define DEBUG_Init(a)	InitUartPort(); UART2Init(); UART2PrintString("UART Initialize \r\n");
    #define DEBUG_Error(a) UART2PrintString(a)
    #define DEBUG_PrintString(a) UART2PrintString(a)
    #define DEBUG_PrintHex(a) UART2PutHex(a)

#endif  //HARDWARE_PROFILE_PIC24FJ64GB002_PIM_H

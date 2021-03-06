/* 
ESP32 anylyse IR remote control protocols
Implement anylyse IR remote control protocols for ESP32 boards with Arduino framework.
Developed by: Walid Amriou
www.walidamriou.com

This work is licensed under:
Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.

Last update: September 2020
*/

#include <Arduino.h>
#include <M5StickC.h>
#include <IRremote.h>

int IR_RECEIVE_PIN = 26;
int LED_BUILTIN = 10;
IRrecv irrecv(IR_RECEIVE_PIN);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);   // Status message will be sent to PC at 9600 baud
    // Just to know which program is running on my Arduino
    M5.begin();
    Serial.println(F("START " __FILE__ " from " __DATE__));
    irrecv.enableIRIn();  // Start the receiver
    Serial.print(F("Ready to receive IR signals at pin "));
    Serial.println(IR_RECEIVE_PIN);
}

// Display IR code
void ircode() {
    // Panasonic has an Address
    if (irrecv.results.decode_type == PANASONIC) {
        Serial.print(irrecv.results.address, HEX);
        Serial.print(":");
    }

    // Print Code
    Serial.print(irrecv.results.value, HEX);
}

// Display encoding type
void encoding() {
    switch (irrecv.results.decode_type) {
    default:
    case UNKNOWN:
        Serial.print("UNKNOWN");
        break;
    case NEC:
        Serial.print("NEC");
        break;
    case SONY:
        Serial.print("SONY");
        break;
    case RC5:
        Serial.print("RC5");
        break;
    case RC6:
        Serial.print("RC6");
        break;
    case DISH:
        Serial.print("DISH");
        break;
    case SHARP:
        Serial.print("SHARP");
        break;
    case SHARP_ALT:
        Serial.print("SHARP_ALT");
        break;
    case JVC:
        Serial.print("JVC");
        break;
    case SANYO:
        Serial.print("SANYO");
        break;
    case MITSUBISHI:
        Serial.print("MITSUBISHI");
        break;
    case SAMSUNG:
        Serial.print("SAMSUNG");
        break;
    case LG:
        Serial.print("LG");
        break;
    case WHYNTER:
        Serial.print("WHYNTER");
        break;
    case AIWA_RC_T501:
        Serial.print("AIWA_RC_T501");
        break;
    case PANASONIC:
        Serial.print("PANASONIC");
        break;
    case DENON:
        Serial.print("Denon");
        break;
    case BOSEWAVE:
        Serial.print("BOSEWAVE");
        break;
    }
}

// Dump out the decode_results structure.
void dumpInfo() {
    // Check if the buffer overflowed
    if (irrecv.results.overflow) {
        Serial.println("IR code too long. Edit IRremoteInt.h and increase RAW_BUFFER_LENGTH");
        return;
    }

    // Show Encoding standard
    Serial.print("Encoding  : ");
    encoding();
    Serial.println("");

    // Show Code & length
    Serial.print("Code      : 0x");
    ircode();
    Serial.print(" (");
    Serial.print(irrecv.results.bits, DEC);
    Serial.println(" bits)");
}

// Dump out the decode_results structure.
void dumpRaw() {
    // Print Raw data
    Serial.print("Timing[");
    Serial.print(irrecv.results.rawlen - 1, DEC);
    Serial.println("]: ");

    for (unsigned int i = 1; i < irrecv.results.rawlen; i++) {
        unsigned long x = irrecv.results.rawbuf[i] * MICROS_PER_TICK;
        if (!(i & 1)) {  // even
            Serial.print("-");
            if (x < 1000)
                Serial.print(" ");
            if (x < 100)
                Serial.print(" ");
            Serial.print(x, DEC);
        } else {  // odd
            Serial.print("     ");
            Serial.print("+");
            if (x < 1000)
                Serial.print(" ");
            if (x < 100)
                Serial.print(" ");
            Serial.print(x, DEC);
            if (i < irrecv.results.rawlen - 1)
                Serial.print(", "); //',' not needed for last one
        }
        if (!(i % 8))
            Serial.println("");
    }
    Serial.println("");                    // Newline
}

// Dump out the decode_results structure.
void dumpCode() {
    // Start declaration
    Serial.print("unsigned int  ");          // variable type
    Serial.print("rawData[");                // array name
    Serial.print(irrecv.results.rawlen - 1, DEC);  // array size
    Serial.print("] = {");                   // Start declaration

    // Dump data
    for (unsigned int i = 1; i < irrecv.results.rawlen; i++) {
        Serial.print(irrecv.results.rawbuf[i] * MICROS_PER_TICK, DEC);
        if (i < irrecv.results.rawlen - 1)
            Serial.print(","); // ',' not needed on last one
        if (!(i & 1))
            Serial.print(" ");
    }

    // End declaration
    Serial.print("};");  //

    // Comment
    Serial.print("  // ");
    encoding();
    Serial.print(" ");
    ircode();

    // Newline
    Serial.println("");

    // Now dump "known" codes
    if (irrecv.results.decode_type != UNKNOWN) {

        // Some protocols have an address
        if (irrecv.results.decode_type == PANASONIC) {
            Serial.print("unsigned int  addr = 0x");
            Serial.print(irrecv.results.address, HEX);
            Serial.println(";");
        }

        // All protocols have data
        Serial.print("unsigned int  data = 0x");
        Serial.print(irrecv.results.value, HEX);
        Serial.println(";");
    }
}

// Dump out the raw data as Pronto Hex.
void dumpPronto() {
    Serial.print("Pronto Hex: ");
    irrecv.dumpPronto(Serial);
    Serial.println();
}

// The repeating section of the code
void loop() {
    if (irrecv.decode()) {  // Grab an IR code
        dumpInfo();           // Output the results
        dumpRaw();            // Output the results in RAW format
        dumpPronto();
        dumpCode();           // Output the results as source code
        Serial.println("");           // Blank line between entries
        irrecv.resume();              // Prepare for the next value
    }
}
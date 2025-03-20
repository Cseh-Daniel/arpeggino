#include <Arduino.h>
#include <MIDIUSB.h>

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).
void noteOn(byte channel, byte pitch, byte velocity)
{
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
  //flush not the best here
  MidiUSB.flush();
}

void noteOff(byte channel, byte pitch, byte velocity)
{
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
  //flush not the best here
  MidiUSB.flush();
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).
void controlChange(byte channel, byte control, byte value)
{
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

// int prssd = 0;
short int bpm = 130;
short int beat = 60000 / bpm;
void setup()
{
  pinMode(2, INPUT);
  digitalWrite(2, LOW);

  pinMode(3, INPUT);
  digitalWrite(3, LOW);
}

void loop()
{
  // if (digitalRead(2) == HIGH && prssd == 0)
  // {
  //   noteOn(0, 48, 64);
  //   MidiUSB.flush();
  //   prssd = 1;
  // }
  // if (digitalRead(3) == HIGH && prssd == 1)
  // {
  //   noteOff(0, 48, 0);
  //   MidiUSB.flush();
  //   prssd = 0;
  // }

  if (digitalRead(2) == HIGH && digitalRead(3) == HIGH)
  {
    noteOn(0, 52, 64);
    delay(beat);

    noteOff(0, 52, 0);
    delay(beat);
  }
  else if (digitalRead(2) == HIGH)
  {
    noteOn(0, 48, 64);
    delay(beat);
    noteOff(0, 48, 0);
    delay(beat);
  }
  else if (digitalRead(3) == HIGH)
  {
    noteOn(0, 50, 64);
    delay(beat);
    noteOff(0, 50, 0);
    delay(beat);
  }
}

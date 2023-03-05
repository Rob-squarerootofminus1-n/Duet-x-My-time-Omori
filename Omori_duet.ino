#define C2  65
#define C3  131
#define GH2 104
#define GH3 208
#define AH2 116
#define AH3 233 
#define C4  262
#define DH3 155
#define DH4 311
#define AH4 466
#define C5  523
#define GH4 416
#define DH5 622 
#define AH5 932 
#define C6 1046
#define G4  392
#define G5 792
#define FH4 370
#define FH5 740
#define GH5 832
#define F4  344
#define F5 688
#define A4  440
#define A5 880
#define D4  288
#define D5  576
#define G3 198
#define E4 329
#define REST 0
#define B4 494
#define CH4 277
#define CH5 554
#define E5 659
#define B2 123
#define D6 1174
#define E6 1318
#define F6 1397
#define CH6 1109
#define B5 988





int piezo = 8; 
int led = 7; 

volatile int beatlength = 200; 
float beatseparationconstant = 0.1;

int duet_x_mytime_omori[] = {
  G4,6, E5, 1, REST,6, B4,6, C5,6, CH5,1, REST,32, G5,2, E5,2, F5,1, G5,-4, CH5,6, D5,1, REST,32, G5,-4, B4,6, C5,1, E5,12, D5,12, C5,12, A4,12, C5,12,
  G4,12, E5,1, REST,6,B4,6, C5,6, CH5,1, G5,2, E5,2, F5,1, G5,-4, CH5,6, D5,1, REST,32, G5,-4, B4,6, C5,1, REST,32, E5,12, D5,12, C5,12, A4,12, C5,12,
  G4,12, A4,6, A4,6, A4,6, GH4,-4, F5,6, E5,4, D5,16, C5,-8, D5,-4, F5,6, E5,4, D5,16, C5,-8, GH4,-4, E4,6, B4,1, REST,64, A4,6, A4,6, A4,6, GH4,-4,
  
  F5,6, E5,4, D5,16, C5,-8, D5,-4, F5,6, E5,4, D5,16, C5,-8, GH4,-4, E4,6, B4,1, AH4,-4, D5,6, E5,-4, C5,6, A4,1, REST,32, A4,6, GH4,-4, C5,6, 
  D5,-4, AH4,6, G4,-4, G4,6, FH4,-4, AH4,6, C5,-4, GH4,6, F5,2, E5,2, E5,1, REST,6, C5,8, D5,8, E5,8, F5,8, G5,1, REST,-4, CH5,6, D5,6, E5,6, F5,6,
  D6,6, E6,6, F6,6, A6,1, REST,64, D5,6, F5,6, D6,6, F6,6, A5,6,E6,6, CH6,2, REST,-4, D5,6, B5,-2, C6,8, A5,8,B5,8, G5,-2, REST,32, G5,8,A5,8,
  B5,8, E6,1, GH5,2, E5,2, C5,2, D5,6, C5,6, D5,6,E5,2, REST,-4, E5,8, G5,8, A5,8, C6,-4, E5,8, G5,8, A5,8, D6,-4, E5,8, G5,8, A5,8, F6,2, E6,2, 
  E6,6, D6,6, A5,6, F5,6, E5,6, F5,6, C6,2, D6,2, D6,6, C6,6, GH5,6, F5,6, E5,6, F5,6, C6,2, GH5,-4, G4,6, E5,1, REST,6, B4,6, C5,6, CH5,1, G5,2,
  E5,2, F5,1, REST,32, G5,-4, CH5,6, D5,1, REST,32, F5,2, E5,2,

};

int notes = sizeof(duet_x_mytime_omori) / sizeof(duet_x_mytime_omori[0]) / 2;

int wholenote = (90000 * 4) / beatlength;

int divider = 0, noteDuration = 0;

void setup() {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = duet_x_mytime_omori[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }

    tone(piezo, duet_x_mytime_omori[thisNote], noteDuration*0.9);

    delay(noteDuration);
    
    
    noTone(piezo);
  }
}

void loop() {
  
}

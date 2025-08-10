// Pure Data Four Osc Drum patch and pattern visualiser //

#include "Adafruit_Arcada.h"
#include <Audio.h>
#include "audio_puredata.h"

#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

Adafruit_Arcada arcada;

uint16_t *framebuffer;

#define WIDTH   80
#define HEIGHT  64
#define SCR     (WIDTH * HEIGHT)
#define SCR2    (ARCADA_TFT_WIDTH * ARCADA_TFT_HEIGHT)

AudioProcessor          proc; 
AudioOutputAnalogStereo audioOut;
AudioAnalyzeRMS         rms;

AudioConnection c1(proc, 0, rms, 0);
AudioConnection c3(proc, 0, audioOut, 0);
AudioConnection c4(proc, 1, audioOut, 1);

  uint8_t cnt;
  float rmsval;

volatile uint32_t rNum;
  
uint32_t trngGetRandomNumber(void){
  uint32_t i = rNum;
  TRNG->INTENSET.reg = TRNG_INTENSET_DATARDY;
  while (i == rNum);
  TRNG->INTENCLR.reg = TRNG_INTENCLR_DATARDY;
  return rNum;
}

void TRNG_Handler(){
  rNum = TRNG->DATA.reg;
  TRNG->INTFLAG.bit.DATARDY = 1;
}

uint16_t color565(uint8_t red, uint8_t green, uint8_t blue) { return ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3); }
  
  float p[WIDTH][HEIGHT];
  float v[WIDTH][HEIGHT];

void setup() {

  MCLK->APBCMASK.reg |= MCLK_APBCMASK_TRNG;
  NVIC_SetPriority(TRNG_IRQn, 0);
  NVIC_EnableIRQ(TRNG_IRQn);
  TRNG->INTENCLR.reg = TRNG_INTENCLR_DATARDY;
  TRNG->CTRLA.reg = TRNG_CTRLA_ENABLE;
 
  srand(trngGetRandomNumber());

  if (!arcada.arcadaBegin()) {while (1);}
  arcada.displayBegin();
  
  arcada.setBacklight(255);

  if (! arcada.createFrameBuffer(ARCADA_TFT_WIDTH, ARCADA_TFT_HEIGHT)) {while (1);}
  framebuffer = arcada.getFrameBuffer();

  AudioMemory(10);

}

void loop() {

  if (rms.available()) {

    if (cnt == 255) {

      for (int y = 0; y < HEIGHT; y++){

        for (int x = 0; x < WIDTH; x++){

          v[x][y] = 0;
          p[x][y] = 0;

        }

      }

    }

    cnt++;

    rmsval = 255 * rms.read();

    v[(WIDTH/2)][(HEIGHT/2)] = rmsval;

  }

  for (int y = 1; y < HEIGHT-1; y++) {

    for (int x = 1; x < WIDTH-1; x++) {

      v[x][y] += sinf(p[x-1][y] + p[x+1][y] + p[x][y-1] + p[x][y+1]) * 0.25f - p[x][y];

    }

  }
  
  for (int y = 0; y < HEIGHT; y++){

    for (int x = 0; x < WIDTH; x++){

      p[x][y] += v[x][y];

      uint8_t coll = 255 - rmsval * sinf(rmsval * p[x][y]);

      framebuffer[(2*x)+(2*y)*ARCADA_TFT_WIDTH] = color565(coll, coll, coll);

    }

  }

  arcada.blitFrameBuffer(0, 0, true, false);

}
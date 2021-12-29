#include <stdio.h>
#include <malloc.h>
#include "wav.h"

int main(int argc, char *argv)
{
    FILE *fp;
    Wav wav;
    RIFF_t riff;
    FMT_t fmt;
    Data_t data; 
    int wave_head;
    int fsize;

    fp = fopen("/home/zorro/Music/chushan_1.wav", "rb");
    if(!fp) {
      printf("can't open file\n ");
    }

    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);
    printf("whole wav size is %d\n", fsize);

    fread(&wav, 1, sizeof(wav), fp);
    riff = wav.riff;
    fmt = wav.fmt;
    data = wav.data;
    wave_head = sizeof(wav);

    printf("wav file head size is %d\n", wave_head);
  
    /** riff **/
    printf("ChunkID \t%c%c%c%c\n", riff.ChunkID[0], riff.ChunkID[1], riff.ChunkID[2], riff.ChunkID[3]);
    printf("ChunkSize \t%d\n", riff.ChunkSize);
    printf("Format \t\t%c%c%c%c\n", riff.Format[0], riff.Format[1], riff.Format[2], riff.Format[3]);

    printf("\n");

    /** fmt **/
    printf("Subchunk1ID \t%c%c%c%c\n", fmt.Subchunk1ID[0], fmt.Subchunk1ID[1], fmt.Subchunk1ID[2], fmt.Subchunk1ID[3]);
    printf("Subchunk1Size \t%d\n", fmt.Subchunk1Size);
    printf("AudioFormat \t%d\n", fmt.AudioFormat);
    printf("NumChannels \t%d\n", fmt.NumChannels);
    printf("SampleRate \t%d\n", fmt.SampleRate);
    printf("ByteRate \t%d\n", fmt.ByteRate);
    printf("BlockAlign \t%d\n", fmt.BlockAlign);
    printf("BitsPerSample \t%d\n", fmt.BitsPerSample);

    printf("\n");

    /** data **/
    printf("blockID \t%c%c%c%c\n", data.Subchunk2ID[0], data.Subchunk2ID[1], data.Subchunk2ID[2], data.Subchunk2ID[3]);
    printf("blockSize \t%d\n", data.Subchunk2Size);

    printf("\n");
    return 0;
}

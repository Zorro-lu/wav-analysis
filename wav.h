#ifndef _WAV_ANALYSIS_
#define _WAV_ANALYSIS_
typedef unsigned char uchar_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

typedef struct WAVE_RIFF {
    /* chunk riff */
    uchar_t ChunkID[4];   /* "RIFF" */
    /* sub-chunk-size */
    uint32_t ChunkSize;   /* 36+SubChunkSize */
    /* sub-chunk-data */
    uchar_t Format[4];   /* "Wave" */
} RIFF_t;

typedef struct WAV_FMT {
    /* sub-chunk "fmt" */
    char Subchunk1ID[4];    /* "fmt " */
    /* sub-chunk-size */
    uint32_t Subchunk1Size; /* 16 for PCM */
    /* sub-chunk-data */
    uint16_t AudioFormat;   /* PCM = 1*/
    uint16_t NumChannels;   /* Mono = 1, Stereo = 2, etc. */
    uint32_t SampleRate;    /* 8000, 44100, etc. */
    uint32_t ByteRate;      /* = SampleRate * NumChannels * BitsPerSample/8 */
    uint16_t BlockAlign;    /* = NumChannels * BitsPerSample/8 */
    uint16_t BitsPerSample; /* 8bits, 16bits, etc. */
} FMT_t;

typedef struct WAV_data {
    /* sub-chunk "data" */
    char Subchunk2ID[4];    /* "data" */
    /* sub-chunk-size */
    uint32_t Subchunk2Size; /* data size */
    /* sub-chunk-data */
//    Data_block_t block;
} Data_t;

typedef struct WAV_fotmat {
    RIFF_t riff;
    FMT_t fmt;
    Data_t data;
} Wav;





#endif /*_WAV_ANALYSIS_*/

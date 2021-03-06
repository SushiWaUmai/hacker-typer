#ifndef ATC_HELLOWORLD_ASM_H_
#define ATC_HELLOWORLD_ASM_H_

// Stolen from:
// https://github.com/SushiWaUmai/asm-basics/blob/main/hello-world/main.asm

#include <stdlib.h>

const size_t helloworld_asm_size = 420;
const char helloworld_asm[] = {
    0x73, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x2e, 0x64, 0x61, 0x74,
    0x61, 0x0a, 0x6d, 0x73, 0x67, 0x20, 0x20, 0x20, 0x20, 0x20, 0x64, 0x62,
    0x20, 0x22, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72,
    0x6c, 0x64, 0x21, 0x22, 0x2c, 0x20, 0x31, 0x30, 0x3b, 0x20, 0x31, 0x30,
    0x20, 0x3d, 0x20, 0x5c, 0x6e, 0x20, 0x4c, 0x46, 0x20, 0x45, 0x4f, 0x46,
    0x0a, 0x6c, 0x65, 0x6e, 0x20, 0x20, 0x20, 0x20, 0x20, 0x65, 0x71, 0x75,
    0x20, 0x24, 0x20, 0x2d, 0x20, 0x6d, 0x73, 0x67, 0x0a, 0x0a, 0x73, 0x65,
    0x63, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x2e, 0x74, 0x65, 0x78, 0x74, 0x0a,
    0x67, 0x6c, 0x6f, 0x62, 0x61, 0x6c, 0x20, 0x20, 0x5f, 0x73, 0x74, 0x61,
    0x72, 0x74, 0x0a, 0x0a, 0x5f, 0x73, 0x74, 0x61, 0x72, 0x74, 0x3a, 0x0a,
    0x09, 0x6d, 0x6f, 0x76, 0x20, 0x72, 0x61, 0x78, 0x2c, 0x20, 0x31, 0x3b,
    0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x20, 0x63, 0x61, 0x6c, 0x6c,
    0x20, 0x6f, 0x66, 0x20, 0x31, 0x20, 0x69, 0x73, 0x20, 0x77, 0x72, 0x69,
    0x74, 0x65, 0x0a, 0x09, 0x6d, 0x6f, 0x76, 0x20, 0x72, 0x64, 0x69, 0x2c,
    0x20, 0x31, 0x3b, 0x20, 0x73, 0x65, 0x74, 0x20, 0x6f, 0x75, 0x74, 0x70,
    0x75, 0x74, 0x20, 0x73, 0x74, 0x72, 0x65, 0x61, 0x6d, 0x20, 0x74, 0x6f,
    0x20, 0x73, 0x74, 0x64, 0x6f, 0x75, 0x74, 0x0a, 0x09, 0x6d, 0x6f, 0x76,
    0x20, 0x72, 0x73, 0x69, 0x2c, 0x20, 0x6d, 0x73, 0x67, 0x3b, 0x20, 0x73,
    0x65, 0x74, 0x20, 0x61, 0x64, 0x72, 0x65, 0x73, 0x73, 0x20, 0x6f, 0x66,
    0x20, 0x74, 0x68, 0x65, 0x20, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x20,
    0x74, 0x6f, 0x20, 0x6f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x0a, 0x09, 0x6d,
    0x6f, 0x76, 0x20, 0x72, 0x64, 0x78, 0x2c, 0x20, 0x6c, 0x65, 0x6e, 0x3b,
    0x20, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x20, 0x6f, 0x66, 0x20, 0x74,
    0x68, 0x65, 0x20, 0x62, 0x79, 0x74, 0x65, 0x73, 0x20, 0x6f, 0x66, 0x20,
    0x74, 0x68, 0x65, 0x20, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20,
    0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x69, 0x6e, 0x67, 0x20, 0x74, 0x68,
    0x65, 0x20, 0x6e, 0x75, 0x6c, 0x6c, 0x20, 0x74, 0x65, 0x72, 0x6d, 0x69,
    0x6e, 0x69, 0x61, 0x74, 0x6f, 0x72, 0x0a, 0x09, 0x73, 0x79, 0x73, 0x63,
    0x61, 0x6c, 0x6c, 0x0a, 0x0a, 0x09, 0x6d, 0x6f, 0x76, 0x20, 0x72, 0x61,
    0x78, 0x2c, 0x20, 0x36, 0x30, 0x3b, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65,
    0x6d, 0x20, 0x63, 0x61, 0x6c, 0x6c, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x65,
    0x78, 0x69, 0x74, 0x0a, 0x09, 0x6d, 0x6f, 0x76, 0x20, 0x72, 0x64, 0x69,
    0x2c, 0x20, 0x30, 0x3b, 0x20, 0x73, 0x65, 0x74, 0x20, 0x72, 0x65, 0x74,
    0x75, 0x72, 0x6e, 0x20, 0x63, 0x6f, 0x64, 0x65, 0x20, 0x74, 0x6f, 0x20,
    0x30, 0x0a, 0x09, 0x73, 0x79, 0x73, 0x63, 0x61, 0x6c, 0x6c, 0x0a, 0x00};

#endif // ATC_HELLOWORLD_ASM_H_

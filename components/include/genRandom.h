#ifndef GENRANDOM_H
#define GENRANDOM_H

#include <stdio.h>
#include <stdint.h>
#include "bootloader_random.h"


char *genRandomString(char string[], int length);
uint32_t atoui32(char *str);

#endif
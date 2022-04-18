/*
 * generate true random number in uint32_t form
 * author: Gary Han
 * date: 2022-04-18
 */

#include <stdio.h>
#include <stdint.h>
#include "bootloader_random.h"

uint32_t atoui32(char *str)
{
    uint32_t result = 0;
    while (*str)
    {
        result = result * 10 + *str - '0';
        str++;
    }
    return result;
}

char *genRandomString(char string[], int length)
{
    bootloader_random_enable();
    char buffer[5] = "\0";
    bootloader_fill_random(buffer, 4);
    bootloader_random_disable();
    printf("randomBuffer: %s\n", buffer);

    uint32_t randomNumber = atoui32(buffer);
    printf("randomNumber: %u\n", randomNumber);

    srand(randomNumber);

    int flag, i;
    for (i = 0; i < length - 1; i++)
    {
        flag = randomNumber % 3;
        switch (flag)
        {
        case 0:
            string[i] = 'A' + rand() % 26;
            break;
        case 1:
            string[i] = 'a' + rand() % 26;
            break;
        case 2:
            string[i] = '0' + rand() % 10;
            break;
        default:
            string[i] = 'x';
            break;
        }
    }
    string[length - 1] = '\0';
    return string;
}

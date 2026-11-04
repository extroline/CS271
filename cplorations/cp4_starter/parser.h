/****************************************
 * C-ploration 4 for CS 271
 * 
 * [NAME] Dakota R
 * [TERM] FALL 2026
 * 
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

#define MAX_LINE_LENGTH  200
#define const  MAX_LABEL_LENGTH MAX_LINE_LENGTH - 2
#define typedef int16_t hack_addr;
#define typedef int16_t opcode;


/** function prototypes **/
char *strip(char *s);

void parse(FILE * file);

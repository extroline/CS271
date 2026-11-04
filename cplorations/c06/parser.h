/****************************************
 * C-ploration 5 for CS 271
 * 
 * [NAME] Dakota R
 * [TERM] FALL 2026
 * 
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h> 
#include <stdint.h>

#define MAX_LINE_LENGTH  200

#define  MAX_LABEL_LENGTH (MAX_LINE_LENGTH - 2) 
typedef int16_t hack_addr;
typedef int16_t opcode;

/** function prototypes **/
char *strip(char *s);

void parse(FILE * file);

char *extract_label(const char *line, char* label);

bool is_Atype (const char *);
bool is_label(const char *);
bool is_Ctype(const char *);

typedef enum instr_type{
    invalid_instruction = -1,
    a_type_instruction,
    c_type_instruction,
} instr_type;

typedef struct c_instruction{
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3; 
} c_instruction;

typedef struct a_instruction{
    union{
        int hack_addr;
        char* label;
    };
    bool is_addr;
} a_instruction;

typedef struct instruction{
    union{
        a_instruction;
        c_instruction;
    };
    instr_type type;
} instruction;
/****************************************
 * C-ploration 5 for CS 271
 *
 * [NAME] Dakoa
 * [TERM] FALL $2026$
 *
 ****************************************/
#include "parser.h"
#include "symtable.h"
#include "error.h"
#include <stdlib.h>
/* Function: strip
 * -------------
 * remove whitespace and comments from a line
 *
 * s: the char* string to strip
 *
 * returns: the stripped char* string
 */
char *strip(char *s)
{

	char s_new[MAX_LINE_LENGTH] = " ";
	int i = 0;
	for (char *s2 = s; *s2; s2++)
	{
		if (*s2 == '/' && *(s2 + 1) == '/')
		{
			break;
		}
		else if (!isspace(*s2))
		{
			s_new[i++] = *s2;
		}
	}
	s_new[i] = '\0';
	strcpy(s, s_new);
	return s;
}

/* Function: parse
 * -------------
 * iterate each line in the file and strip whitespace and comments.
 *
 * file: pointer to FILE to parse
 *
 * returns: nothing
 */
void parse(FILE *file)
{
	char line[MAX_LINE_LENGTH] = {0};
	//hack_addr instr_num = 0;


	unsigned int line_num = 0;
	unsigned int instr_num = 0;

	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		if(instr_num > MAX_INSTRUCTIONS)
		{
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);

		}
		strip(line);
		if (*line == '\0')
		{
			
			continue;
		}
		char inst_type = ' ';
		if (is_Atype(line))
		{
			inst_type = 'A';
		}
		if (is_label(line))
		{
			inst_type = 'L';
		}
		if (is_Ctype(line))
		{

			inst_type = 'C';
		}
		if (is_label(line))
		{
			char label[MAX_LINE_LENGTH] = {0};
			extract_label(line, label);
			strcpy(line, label);


			if( !isalpha(label[0]) )
			{
				exit_program(EXIT_INVALID_LABEL, line_num, line);

			}
			if(symtable_find(label) != NULL)
			{
				exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
			}
			symtable_insert(label, instr_num);
			continue; 

		}
		// printf("%c  %s\n", inst_type, line);
		printf("%u: %c  %s\n", instr_num, inst_type, line);
		instr_num++;
	}
}

bool is_Atype(const char *line)
{
	if (*line == '@')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool is_label(const char *line)
{
	int last = strlen(line) - 1;

	if (line[0] == '(' && line[last] == ')')
	{
		return true;
	}
	else
	{
		return false;
	}
}

char *extract_label(const char *line, char *label)
{
	int last = strlen(line) - 1;
	if (line[0] == '(' && line[last] == ')')
	{

		int label_idx = 0;
		for (int i = 1; i < last; i++)
		{
			label[label_idx] = line[i];
			label_idx++;
		}
		label[label_idx] = '\0';
	}
	return label;
}

bool is_Ctype(const char *line)
{
	int last = strlen(line) - 1;
	if (*line == '@' || (line[0] == '(' && line[last] == ')'))
	{
		return false;
	}
	else
	{
		return true;
	}
}

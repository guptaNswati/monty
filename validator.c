#include "monty.h"

/**
 * validator - checks to see if instruction is valid opcode or not
 * @opcode: incoming operator
 * Return: void
 */

void validator(char *opcode, int line_number)
{
	int i = 0, total = 0;
	char *valid_codes[] = {	"pall", "pint", "pop", "swap", "add",
				"nop", "sub", "div", "mul", "mod", "pchar",
				"pstr",	"rotl",	"rotr"};
	while (i < 14)
	{
		if (strcmp(opcode, valid_codes[i]) == 0)
			total += 1;
		i++;
	}
	if (total == 0)
		invalid_instruction(line_number, opcode);
}
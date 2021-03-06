#include "monty.h"

/**
 * main - main function for monty byte code intepreter
 * @ac: command line argument count (should be 2)
 * @av: string array of command line arguments. av[1] should be file name
 * Return: 0 upon non-error exit
 */

int main(int ac, char *av[])
{
	FILE *f;
	size_t n = 0, line = 1;
	char *cmd = NULL, *curr_cmd, *push_arg;
	int flag = 0;
	stack_t *head = NULL;

	/* Checks if argcount is valid and file can be opened  */
	ac_check(ac);
	av_check(av[1]);
	f = fopen(av[1], "r");
	while (-1 != getline(&cmd, &n, f))
	{
		curr_cmd = strtok(cmd, " \t\r\n\v\f");
		if (curr_cmd == NULL || curr_cmd[0] == '#' ||
		    strcmp("nop", curr_cmd) == 0)
		{
			line++;
			continue;
		}
		if (strcmp(curr_cmd, "push") == 0)
		{
			push_arg = strtok(NULL, " \t\r\n\v\f");
			push(&head, push_arg, &flag, line);
		}
		else
		{
			/* checks if given arg is a valid instruction or not*/
			instrction_caller(curr_cmd, line, &head, &flag);
		}
		line++;
	}
	return (0);
}

#include "monty.h"

/**
* swap_tops - swaps the top two elements of the stack_t list if list is
* two elements or long.
* @head: pointer to head pointer of stack_t list.
* @num: line number of opcode
* Return: nothing
**/
void swap_tops(stack_t **head, unsigned int num)
{
	int tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%d: can't swap, stack too short\n", num);
		if (*head)
		{
			free(*head);
			*head = NULL;
		}
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}

/**
* chr_top - prints the char at  top of the stack_t list if its in ascii range
* and list is not empty.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void chr_top(stack_t **head, unsigned int num)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", num);
		freelist(head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
* str_top - prints the string starting at the top of the stack_t list, if
* its not empty and values are in ascii range.
* @head: pointer to head pointer of list
* @num: line number of opcode
* Return: nothing
**/
void str_top(stack_t **head, unsigned int num)
{
	stack_t *tmp;
	(void)num;

	if (*head != NULL)
	{
		tmp = *head;
		while (tmp && (tmp->n > 0 && tmp->n < 128))
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
	}
	printf("\n");
}

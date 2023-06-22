#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * my_pall - prints the stack
 * @head: stack head
 * @counter: void
 * Return: void
*/

void my_pall(stack_t **head, unsigned int counter)
{
	stack_t *ele;
	(void)counter;

	ele = *head;
	if (ele == NULL)
		return;
	while (ele)
	{
		printf("%d\n", ele->n);
		ele = ele->next;
	}
}

/**
 * my_push - add node to the stack
 * @head: stack head
 * @counter: num of elements
 * Return: void
*/

void my_push(stack_t **head, unsigned int counter)
{
	int num, i = 0, arg = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				arg = 1;
		}
		if (arg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(bus.arg);
	if (bus.lifi == 0)
	{
		addnode(head, num);
	}
	else
	{
		addqueue(head, num);
	}
}

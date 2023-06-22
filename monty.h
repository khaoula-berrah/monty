#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#define BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structs */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* ext var */
extern glob_var var;

/**
 * struct var - glob var to store pointer of stack, then 
 * current code instruction, file included.
 * @file: the pointer to the file include.
 * @insert_code: code of current instruction.
 * @stack: pointer of pointer to the stack.
 * 
 * Description: global structure variable.
 */
typedef struct var
{
	int insert_code;
	stack_t **stack;
        FILE *file;
} glob_var;

typedef void (*function)(stack_tt **stack, unsigned int line_number);

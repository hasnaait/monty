#include "monty.h"

/**
 * add_Stack - Adds a node to the stack.
 * @nw: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_Stack(stack_t **nw, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (nw == NULL || *nw == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nw;
		return;
	}
	tmp = head;
	head = *nw;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * prStack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: line number of  the opcode.
 */

void prStack(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	(void)ln;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, ln);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, ln);
	printf("%d\n", (*stack)->n);
}

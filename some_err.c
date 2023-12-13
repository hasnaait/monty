#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @code_err: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void err(int code_err, ...)
{
	va_list ag;
	char *op;
	int long_num;

	va_start(ag, code_err);
	switch (code_err)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
		break;
	case 3:
		long_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", long_num, op);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
		break;
	default:
		break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @code_err: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_err(int code_err, ...)
{
	va_list ag;
	char *op;
	int long_num;

	va_start(ag, code_err);
	switch (code_err)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
		break;
	case 8:
		long_num = va_arg(ag, unsigned int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", long_num, op);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
		break;
	default:
		break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * str_error - handles errors.
 * @code_err: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void str_error(int code_err, ...)
{
	va_list ag;
	int long_num;

	va_start(ag, code_err);
	long_num = va_arg(ag, int);
	switch (code_err)
	{
	case 10:
		fprintf(stderr, "L%d: can't pchar, value out of range\n", long_num);
		break;
	case 11:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", long_num);
		break;
	default:
		break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

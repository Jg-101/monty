#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - Prints pop err messgs for null stacks.
 * @line_number: Line num in script where err happened.
 *
 * Return: failure message always.
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint err messgs for null stacks.
 * @line_number: Line number in Monty bc file where err occurred.
 *
 * Return: failure message always.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty math func err messgs
 *                     for stacks/queues smaller than 2 nodes.
 * @line_number: Line number in Monty bc file where err occurred.
 * @op: Op where the err occurred.
 *
 * Return: failure message always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints div err messgs for div by 0.
 * @line_number: Line number in Monty bc file where err occurred.
 *
 * Return: failure message always.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pcharacter err messgs for null stacks
 *               null stacks and non-char val.
 * @line_number: Line number in Monty bc file where err occurred.
 * @message: The correlation err messg to print.
 *
 * Return: failure message always.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

#include "monty.h"

/**
 * set_op_tok_error - Sets last elem of op_toks to be an err code.
 * @error_code: Int to store as a str in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, j = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (j < toks_len)
	{
		new_toks[j] = op_toks[j];
		j++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[j++] = exit_str;
	new_toks[j] = NULL;
	free(op_toks);
	op_toks = new_toks;
}

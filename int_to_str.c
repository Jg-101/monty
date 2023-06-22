#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * get_int - gets a char pntr to new str containing int
 * @num: num to convert to str
 *
 * Return: char pntr to newly created str
 */
char *get_int(int num)
{
	unsigned int temp;
	int lt = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	lt = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		lt++; /* negative sign */
	ret = malloc(lt + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - gets the abs val of an int
 * @j: int to get abs val in prog
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int j)
{
	if (j < 0)
		return (-(unsigned int)j);
	return ((unsigned int)j);
}

/**
 * get_numbase_len - gets length of buff needed for an unsigned int in the prog
 * @num: num to get length needed in prog
 * @base: base of number representation used by buffer
 *
 * Return: int containing length of buff needed
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buff with correct num up to base 36
 * @num: num to conv to str given base
 * @base: base of num used in conv, only works up to base 36
 * @buff: buffer to fill with result of conv
 * @buff_size: size of buffer in byte
 *
 * Return: always void on success.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int remp, j = buff_size - 1;

	buff[buff_size] = '\0';
	while (j >= 0)
	{
		remp = num % base;
		if (remp > 9) /* return lowercase ascii val representation */
			buff[j] = remp + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[j] = remp + '0';
		num /= base;
		j--;
	}
}

#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - takes a str and seperates its wrds
 *
 * @str: str to seperate into wrds
 * @delims: delimitors to use to delimit wrds
 *
 * Return: 2D arr of pntrs to each wrd
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, j = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (j < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[j] = malloc((wordLen + 1) * sizeof(char));
		if (words[j] == NULL)
		{
			while (j >= 0)
			{
				j--;
				free(words[j]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[j][n] = *(str + n);
			n++;
		}
		words[j][n] = '\0';
		str = get_next_word(str, delims);
		j++;
	}
	words[j] = NULL;
	return (words);
}

/**
 * is_delim - checks if stream has delimitor character
 *
 * @ch: char in stream
 *
 * @delims: Pntr to null terminated arr of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
	int j = 0;

	while (delims[j])
	{
		if (delims[j] == ch)
			return (1);
		j++;
	}
	return (0);
}

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: str to get word length from curr wrd
 * @delims: delimitors to use to delimit wrds
 *
 * Return: wrd length of curr word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, j = 0;

	while (*(str + j))
	{
		if (is_delim(str[j], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[j], delims))
			break;
		j++;
	}
	return (wLen);
}

/**
 * get_word_count - gets the word count of a str
 *
 * @str: str to get wrd count from
 * @delims: delimitors to use to delimit wrds
 *
 * Return: the word count of the str
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pendin = 1, j = 0;

	while (*(str + j))
	{
		if (is_delim(str[j], delims))
			pendin = 1;
		else if (pendin)
		{
			pendin = 0;
			wc++;
		}
		j++;
	}
	return (wc);
}

/**
 * get_next_word - gets the next word in a str
 *
 * @str: str to get next wrd from
 * @delims: delimitors to use to delimit wrds
 *
 * Return: pntr to first character of next word
 */

char *get_next_word(char *str, char *delims)
{
	int pendin = 0;
	int j = 0;

	while (*(str + j))
	{
		if (is_delim(str[j], delims))
			pendin = 1;
		else if (pendin)
			break;
		j++;
	}
	return (str + j);
}

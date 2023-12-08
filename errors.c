#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character x to stderr
 * @x: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char x)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 * _putfd - writes the character x to given fd
 * @x: The character to print
 * @f: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char x, int f)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f, buf, i);
		i = 0;
	}
	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @f: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int f)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, f);
	}
	return (i);
}

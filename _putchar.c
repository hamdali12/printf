#include "main.h"
#include <unistd.h>

/**
 * _putchar - Write a character to stdout
 * @c: The character to print
 *
 * Return: The number of characters printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

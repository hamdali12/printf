#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            printed_chars++;
        }
        else
        {
            format++;
            if (*format == '\0')
            {
                va_end(args);
                return (-1);
            }

            switch (*format)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    printed_chars++;
                    break;
                case 's':
                    printed_chars += print_string(va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    printed_chars++;
                    break;
                case 'd':
                case 'i':
                    printed_chars += print_int(va_arg(args, int));
                    break;
                default:
                    va_end(args);
                    return (-1);
            }
        }

        format++;
    }

    va_end(args);
    return (printed_chars);
}

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(const char *str)
{
    int printed_chars = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        putchar(*str);
        printed_chars++;
        str++;
    }

    return (printed_chars);
}

/**
 * print_int - Prints an integer.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(int num)
{
    if (num < 0)
    {
        putchar('-');
        num = -num;
    }

    int printed_chars = 0;
    if (num == 0)
    {
        putchar('0');
        return (1);
    }
    if (num / 10)
    {
        printed_chars += print_int(num / 10);
    }
    putchar(num % 10 + '0');
    return (printed_chars + 1);
}

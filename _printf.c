#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str)
                {
                    while (*str)
                    {
                        _putchar(*str);
                        str++;
                        count++;
                    }
                }
            }
            else if (*format == '%')
            {
                _putchar('%');
                count++;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

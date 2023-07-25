#include "main.h"

/**
 * get_precision - Gets the precision value from the format string
 * @format: Format string
 * @types: List of arguments
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int get_precision(const char *format, va_list types,
int flags, int width, int precision, int size)
{
int i = 0, j = 0, prec = 0;

UNUSED(types);
UNUSED(flags);
UNUSED(width);
UNUSED(size);

while (format[i] != '\0')
{
if (format[i] == '.')
{
j = i + 1;
while (format[j] >= '0' && format[j] <= '9')
{
prec = prec * 10 + (format[j] - '0');
j++;
}
if (prec == 0)
prec = -1;
return (prec);
}
i++;
}
return (-1);
}

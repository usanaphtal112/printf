#include "main.h"

/**
 * get_width - Gets the width value from the format string
 * @format: Format string
 * @types: List of arguments
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int get_width(const char *format, va_list types,
int flags, int width, int precision, int size)
{
int i = 0, wid = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '*')
{
wid = va_arg(types, int);
if (wid < 0)
{
wid = -wid;
flags |= F_MINUS;
}
return (wid);
}
if (format[i] >= '0' && format[i] <= '9')
{
wid = wid * 10 + (format[i] - '0');
if (format[i + 1] < '0' || format[i + 1] > '9')
return (wid);
}
}
return (width);
}

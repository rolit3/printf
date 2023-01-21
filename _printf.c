#include<stdio.h>
#include<stdarg.h>
/**
 * main - Entry point
 * @brief Myprintf function prints user entries in stdout
 * @brief convert function converts the integer number into octal, hex, etc
 * @param '' is an empty entry
 * Return: Always (0)
 */

void Myprintf(char *, ...);
char *convert(unsigned int, int); /*Convert integer number into other.*/
int main(void)
{
Myprintf("ALX %d \n", 2022);
return (0);
}
void Myprintf(char *format, ...)
{
char *traverse;
int i;
char *s;
/*Module 1: Initializing Myprintf's arguments*/
va_list arg;
va_start(arg, format);
for (traverse = format; *traverse != '\0'; traverse++)
{
while (*traverse != '%')
{
putchar(*traverse);
traverse++;
}
traverse++;
/*Module 2: Fetching and executing arguments*/
switch (*traverse)
{
/*Fetch char argument*/
case 'c':
i = va_arg(arg, int);
putchar(i);
break;
/*Fetch Decimal/Integer argument*/
case 'd':
i = va_arg(arg, int);
if (i < 0)
{
i = -i;
putchar('-');
}
puts(convert(i, 10));
break;
/*Fetch Octal representation*/
case 'o':
i = va_arg(arg, unsigned int);
puts(convert(i, 8));
break;
/*Fetch string*/
case 's':
s = va_arg(arg, char *);
puts(s);
break;
/*Fetch Hexadecimal representation*/
case 'x':
i = va_arg(arg, unsigned int);
puts(convert(i, 16));
break;
}
}
/*Module 3: Closing argument list to necessary clean-up*/
va_end(arg);
}
char *convert(unsigned int num, int base)
{
static const char Representation[] = "0123456789ABCDEF";
static char buffer[50];
char *ptr;
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = Representation[num % base];
num /= base;
} while (num != 0);
return (ptr);
}

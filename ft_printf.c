/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2023/10/24 13:53:34 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printformat(va_list args, char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_length += ft_printdigit(va_arg(args, int), 10, 0);
	else if (format == 'p')
		print_length += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		print_length += ft_printdigit(va_arg(args, unsigned int), 10, 0);
	else if (format == 'x')
		print_length += ft_printdigit(va_arg(args, unsigned int), 16, 0);
	else if (format == 'X')
		print_length += ft_printdigit(va_arg(args, unsigned int), 16, 1);
	else if (format == '%')
		print_length += write(1, "%", 1);
	else
		print_length += write(1, &format, 1);
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		charactercount;

	i = 0;
	charactercount = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			charactercount += printformat(args, format[i + 1]);
			i++;
		}
		else
			charactercount += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (charactercount);
}

/*
int main(void) {


// Test 1: CHARACTER
int message = 109;

printf("Standard printf for CHARACTERS (C) : %c\n", message);
ft_printf("Custom ft_printf for CHARACTERS (C): %c\n\n", message);


// Test 2: Printing strings
char *str = "Hello, world!";
printf("Standard printf for STRINGS (S) : %s\n", str);
ft_printf("Custom ft_printf for STRINGS (S): %s\n\n", str);

// Test 3: Printing pointers
int num = 42;
void *ptr = &num;
printf("Standard printf for POINTERS (P) : %p\n", ptr);
ft_printf("Custom ft_printf for POINTERS (P): %p\n\n", ptr);


// Test 4: Printing decimals
int numb= 42;
printf("Standard printf for DECIMALS (D)  : %d\n", numb);
ft_printf("Custom ft_printff for DECIMALS (D): %d\n\n", numb);

// Test 5: Printing integers
int numbe = 662213;
printf("Standard printf for INTEGERS (I)  : %i\n", numbe);
ft_printf("Custom ft_printff for INTEGERS (I): %i\n\n", numbe);

// Test 6: Unsigned decimal
int number = 17812;
printf("Standard printf for UNSIGNED DECIMALS (U)  : %u\n", number);
ft_printf("Custom ft_printff for UNSIGNED DECIMALS (U): %u\n\n", number);

 // Test 7: Printing hexadecimal
int hex = 0x1A3;
printf("Standard printf for NUMBER IN HEXADECIMAL LOW (x) : %x\n", hex);
ft_printf("Custom ft_printf for NUMBER IN HEXADECIMAL LOW (x): %x\n\n", hex);

 // Test 8: Printing hexadecimal
int hexe = 0x1A3;
printf("Standard printf for NUMBER IN HEXADECIMAL UPP (X) : %X\n", hexe);
ft_printf("Custom ft_printf for NUMBER IN HEXADECIMAL UPP (X): %X\n\n", hexe);

 // Test 9: Printing Percentage
printf("Standard printf for PERCENT SIGN (%%) : %%\n");
ft_printf("Custom ft_printf for PERCENT SIGN (%%): %%\n\n");

// Test 10: Printing a mix of formats
int a = 10, b = 20, c = 30;
printf("Standard printf for MIX FORMATS : a=%d, b=%d, c=%d\n", a, b, c);
 ft_printf("Custom ft_printf for MIX FORMATS: a=%d, b=%d, c=%d\n\n", a, b, c);

// Test 11: Printing nulls
printf("Standard printf for NULL : a=%s, b=%p\n", (char *)NULL, NULL);
ft_printf("Custom ft_printf for NULL: a=%s, b=%p\n", (char *)NULL, NULL);


return (0);
}

*/
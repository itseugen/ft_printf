# ft_printf
### My own version of the popular printf function
It handles the following identifiers:
- * %c Prints a single character
- * %s Prints a string
- * %p Prints a (void *) pointer in hexadecimal format
- * %d Prints a decimal number
- * %i Prints an integer
- * %u Prints an unigned integer
- * %x Prints a number in lowercase hexadecimal
- * %X Prints a number in uppercase hexadecimal
- * %% Prints a percent sign

- * It also handles a single % with a missing identifier.
- Just like in the original printf it just skippes the '%' and continues afterwards.
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c ft_putchar_str.c ft_putnbrs.c
BINARIES = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(SOURCE) $(BINARIES)
	ar rcs $(NAME) $(BINARIES)

clean:
	rm -f $(BINARIES) $(BONUSBIN)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus


NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
MAKEFILE = Makefile
LIBFTPRINT = ft_print.h

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c type_cs.c type_num.c type_xXp.c

OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBC = ar -rcs #preguntar al chati

%.o : %.c $(MAKEFILE) $(LIBFTPRINT)
	${CC} ${FLAGS} -c $< -o $@

all : $(NAME)
 
$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) ./ 
	$(LIBC) $(NAME) $(OBJS) $(LIBFT)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re

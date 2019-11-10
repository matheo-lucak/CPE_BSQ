##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

CC	=	gcc

SRC	=	get_map_tool.c	\
		bsq.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CPPFLAGS	=	-I./include/

LDFLAGS		=	-L./lib

LDLIBS		=	-lmy

LIB	=	./lib/libmy.a


$(NAME):	 $(LIB) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

all:	$(NAME)

debug:	fclean $(LIB) $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -W -Wall -Wextra -g

gdb:	fclean $(LIB) $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -W -Wall -Wextra -g
	gdb ./$(NAME)

tests_run:
	make -C tests/
	./tests/unit_tests
$(LIB):
	make -C ./lib/my/
clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re:	fclean all

.PHONY:	$(NAME) all clean fclean

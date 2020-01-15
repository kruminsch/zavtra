
SRC	=	main.c					\
		my_str_to_word_array.c	        	\
		sort_words.c				\



OBJ	=	$(SRC:.c=.o)				\

NAME	=	my_swap

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -g3 -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

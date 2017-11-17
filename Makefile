##
## Makefile for BSQ in /home/dommer_c/rendu/CPE_2015_BSQ
## 
## Made by clement dommerc
## Login   <dommer_c@epitech.net>
## 
## Started on  Mon Dec 14 18:03:57 2015 clement dommerc
## Last update Fri Nov 17 00:34:13 2017 qlem
##

CC=	gcc

RM=	rm -f

CFLAGS=	-Wextra -Wall -Werror -W -ansi -pedantic -O2

NAME=	bsq

SRC=	manag_mem.c	\
	create_tab.c	\
	bsq.c

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) ./include/*~

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

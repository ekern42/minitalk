# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 11:19:49 by ekern             #+#    #+#              #
#    Updated: 2022/05/17 13:19:27 by ekern            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Werror -Wall -Wextra

INCLUDES = srcs/minitalk.h

LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)

SRCS = \
	srcs/server.c \
	srcs/client.c

OBJS = ${SRCS:c=o}

all : $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER) : $(OBJS)
	$(CC) $(CFLAGS) srcs/server.c $(LIBFT_FILE) -o $@

$(CLIENT) : $(OBJS)
	$(CC) $(CFLAGS) srcs/client.c $(LIBFT_FILE) -o $@

srcs/%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<
	
clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f client
	@rm -f server

big_clean : fclean $(LIBFT_FILE)_fclean

re : fclean all

# Libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFT_FILE)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean

.PHONY : all clean fclean big_clean re 
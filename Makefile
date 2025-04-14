NAME	= fractol

MLX = MLX42/build/libmlx42.a
FLAG_MLX = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
INCLUDE = -I /Users/${USER}/.brew/Cellar/glfw/3.4/include/GLFW
LIB = -L /Users/${USER}/.brew/Cellar/glfw/3.4/lib

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -O3 -ffast-math -fsanitize=address -g

MOBJS	= ${SRCS:%.c=%.o}
SRCS	=  main.c  ft_julia.c   ft_mandelbrot.c  utils.c


all: $(NAME)

$(NAME): $(MOBJS)
	@$(CC) $(CFLAGS) $(FLAG_MLX) $(MOBJS) $(MLX) $(LIB) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
	@rm -f $(MOBJS)

fclean: clean
	@rm -f $(NAME)


re: fclean all
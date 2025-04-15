/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:22:07 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/14 18:07:23 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// void leaks(){
// 	system("leaks fractol");
// }
void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s)
	{
		write(fd, s, strlen(s));
		write(fd, "\n", 1);
	}
}

int	exit_fractal(t_fractol *fractal)
{
	mlx_close_window(fractal->mlx);
	free(fractal);
	exit(0);
	return (0);
}

void	ft_error(void)
{
	ft_putendl_fd("Usage: ./fractol <fractal>", 1);
	ft_putendl_fd("Available fractals: mandelbrot, julia", 1);
	exit(0);
}

void	draw_fractals(void *fract)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)fract;
	fractol->x = 0;
	while (fractol->x < SIZE_W)
	{
		fractol->y = 0;
		while (fractol->y < SIZE_H)
		{
			if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
				ft_mandelbrot(fract);
			else if (ft_strncmp(fractol->name, "julia", 5) == 0)
				ft_julia(fract);
			else
				exit(1);
			fractol->y++;
		}
		fractol->x++;
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractal;
	double		zoom_level;

	(void)xdelta;
	fractal = (t_fractol *)param;
	zoom_level = 1.20;
	if (ydelta > 0)
		fractal->zoom = fractal->zoom * zoom_level;
	else if (ydelta < 0)
		fractal->zoom = fractal->zoom / zoom_level;
}

int	main(int ac, char **av)
{
	int	i;
		t_fractol *fract;

	// atexit(leaks);
	i = 0;
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fract = malloc(sizeof(t_fractol));
		if (ac == 4)
		{
			fract->Cx = ft_atoi(av[2]);
			fract->Cy = ft_atoi(av[3]);
		}
		fract->name = av[1];
		init_var(fract);
		fract->mlx = mlx_init(SIZE_H, SIZE_W, "fract-ol", false);
		fract->image = mlx_new_image(fract->mlx, SIZE_W, SIZE_H);
		mlx_image_to_window(fract->mlx, fract->image, 0, 0);
		mlx_scroll_hook(fract->mlx, &my_scrollhook, fract);
		mlx_loop_hook(fract->mlx, draw_fractals, fract);
		mlx_loop(fract->mlx);
		exit_fractal(fract);
	}
	else
		ft_error();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:14:45 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/14 16:46:50 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE_H 800
#define SIZE_W 800


typedef struct s_fractol
{
	double		Zx;
	double		Zy;
	double		Cx;
	double		Cy;
	int			x;
	int			y;
	int i;
	int  j;
	int color;
	int color_2 ;
	double		zoom;
	double		offset_x;
	double		offset_y;
	char		*name;
	int			iteration;
	mlx_t		*mlx;
	mlx_image_t	*image;

}				t_fractol;

int ft_strcmp(char *s1, char *s2);
//--------------------- utils -----------------------
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			ft_atoi(char *str);
void			init_var(t_fractol *fract);
int get_rgba(int r, int g, int b, int a);
int get_rg_l(int r, int g, int b, t_fractol *fract);
int get_rg_julia(int r, int g, int b, t_fractol *fract);
//-------------------- mandelbrot --------------------
void			ft_mandelbrot(t_fractol *fract);

//-------------------- julia -------------------------
void			ft_julia(t_fractol *fract);
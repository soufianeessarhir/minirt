/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:58:37 by sessarhi          #+#    #+#             */
/*   Updated: 2025/02/20 10:16:06 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINED_BONUS_H
# define DEFINED_BONUS_H
# define BUFFER_SIZE 4096
# define WIDTH 2000
# define HEIGHT 1800
# define FLOAT double
# define M_PI 3.14159265358979323846
# define EPSILON 1e-6
# define SHADOW_BIAS 0.0001f
# define SUCCESS 0
# define ERROR -1
# define EMPTY_FILE "error file empty or line too long\n"

typedef struct _s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef t_vector	t_point;
#endif
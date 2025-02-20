/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_create_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:24:38 by ibes-sed          #+#    #+#             */
/*   Updated: 2025/02/20 10:11:37 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory_bonus.h"

size_t	align_up(size_t n, size_t align)
{
	return (((n) + (align) - 1) & ~((align) - 1));
}

t_arena	*arena_create(void)
{
	return (arena_create_with_params(DEFAULT_CHUNK_SIZE, true, malloc, free));
}

void	setup_arena2(t_arena *arena,
	bool allow_resize, void *(*alloc_fn)(size_t), void (*free_fn)(void *))
{
	arena->allow_resize = allow_resize;
	arena->total_allocated = 0;
	arena->total_used = 0;
	arena->alloc_fn = alloc_fn;
	arena->free_fn = free_fn;
}

t_arena	*arena_create_with_params(size_t chunk_size, bool allow_resize,
						void *(*alloc_fn)(size_t), void (*free_fn)(void *))
{
	t_arena			*arena;
	t_arena_chunk	*chunk;

	if (chunk_size < MIN_CHUNK_SIZE)
		chunk_size = MIN_CHUNK_SIZE;
	chunk_size = align_up(chunk_size, ARENA_ALIGNMENT);
	if (!alloc_fn)
		alloc_fn = malloc;
	if (!free_fn)
		free_fn = free;
	arena = (t_arena *)alloc_fn(sizeof(t_arena));
	if (!arena)
		return (NULL);
	arena->chunk_size = chunk_size;
	setup_arena2(arena, allow_resize, alloc_fn, free_fn);
	chunk = arena_allocate_chunk(arena, chunk_size);
	if (!chunk)
	{
		free_fn(arena);
		return (NULL);
	}
	arena->first = chunk;
	arena->current = chunk;
	return (arena);
}

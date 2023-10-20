/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:47:34 by anlima            #+#    #+#             */
/*   Updated: 2023/10/20 21:22:30 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	g_exit = 0;

int	main(int argc, char **argv, char **env)
{
	(void)(argc);
	(void)(argv);
	init_program(env);
	while (1)
	{
		rl_on_new_line();
		term()->command = readline(PROMPT);
		if (term()->command == NULL)
			break ;
		if (*term()->command == '\0')
			continue ;
		lexer();
		add_history(term()->command);
		if (term()->exit_flag)
		{
			term()->exit_flag = 0;
			g_exit = 127;
		}
		clean_mallocs();
		remove(HERETXT);
	}
	return (0);
}

// TODO: - make `cat | cat | ls` work as intended <=
// TODO: - make try executing a dir throw the same error as bash

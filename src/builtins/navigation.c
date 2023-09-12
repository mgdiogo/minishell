/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:13:34 by anlima            #+#    #+#             */
/*   Updated: 2023/09/12 16:11:17 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_cd(void);
void	execute_pwd(void);

void	execute_cd(void)
{
	if (term()->cmd_table[1] == NULL)
	{
		if (term()->home == NULL)
			return (perror("cd"));
		if (chdir(term()->home) != 0)
			return (perror("cd"));
	}
	else
	{
		if (chdir(term()->cmd_table[1]) != 0)
			return (perror("cd"));
	}
}

void	execute_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path)
		printf("%s%s%s\n", BLUE, path, CLEAR);
	else
		perror("pwd");
	free(path);
}

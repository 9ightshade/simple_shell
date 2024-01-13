#include "shell.h"

/**
 * function_filter - Filters built-ins and sends them to the appropriate function.
 *
 * @commands: Double pointer from the command line.
 * @env: Environment variable.
 *
 * Return: Returns the result of the exec_cmd function.
 */
int function_filter(char **commands, char **env)
{
    int option = 0;
    char *builtin[7] = {"exit", "cd", "env", "holberton", "unsetenv", "setenv", NULL};

    /* If no args at all, continue */
    if (commands[0] == NULL)
        return (1);

    /* Loop through the built-in commands to find a match */
    while (builtin[option] != NULL)
    {
        if (_strcmp(builtin[option], commands[0]) == 0)
            break;
        option++;
    }

    /* Execute the corresponding built-in function or command */
    switch (option)
    {
    case 0: /* Exit */
        if (commands[1] == NULL)
            call_exit(commands); /* Only 'exit' is typed */
        else
            call_exit_status(commands); /* 2nd arg after 'exit' */
        break;
    case 1:
        call_cd(commands); /* 'cd' is typed */
        break;
    case 2:
        call_env(env); /* 'env' is typed */
        break;
    case 3:
        WhoAmI(); /* 'holberton' is typed */
        break;
    case 4:
        call_unsetenv(env, commands); /* 'unsetenv' is typed */
        break;
    case 5:
        call_setenv(env, commands); /* 'setenv' is typed */
        break;
    default:
        return (exec_cmd(commands, env)); /* No built-in found, execute command */
    }

    return (option);
}


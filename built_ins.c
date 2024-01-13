#include "shell.h"

/**
 * call_exit - Exits the shell.
 *
 * @args: The arguments passed to the exit command.
 *
 * Return: void
 */
void call_exit(char **args)
{
    /* Free the allocated memory for arguments and exit the shell */
    free(*args);
    free(args);
    exit(EXIT_SUCCESS);
}

/**
 * call_exit_status - Exits the shell with a specific status.
 *
 * @args: The arguments passed to the exit status command.
 *
 * Return: 0 on success, -1 on failure.
 */
int call_exit_status(char **args)
{
    int status;

    /* Convert the exit status argument to an integer */
    status = _exit_atoi(args[1]);

    if (status == -1)
    {
        perror("hsh");
        return (0);
    }
    else
    {
        /* Exit the shell with the specified status */
        exit(status);
    }
}

/**
 * call_cd - Changes the current working directory.
 *
 * @args: The arguments passed to the cd command.
 *
 * Return: 0 on success, -1 on failure.
 */
int call_cd(char **args)
{
    char *targetDir = NULL, *home = NULL;

    /* Get the home directory */
    home = _getenv(environ, "HOME");

    if (args[1])
    {
        /* For "cd ~", go to the home directory */
        if (_strcmp(args[1], "~"))
        {
            targetDir = home;
        }
        /* For "cd -", go to the previous directory */
        else if (_strcmp(args[1], "-"))
            targetDir = _getenv(environ, "OLDPWD");
        else
            targetDir = args[1];
    }
    else
        targetDir = home;

    /* If the target directory is the home directory, change to it */
    if (targetDir == home)
        chdir(targetDir);
    /* If the target directory exists and has read permissions, change to it */
    else if (access(targetDir, F_OK | R_OK) == 0)
        chdir(targetDir);
    else
        perror("hsh");

    return (0);
}

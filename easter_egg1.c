#include "shell.h"

/**
 * WhoAmI - Reads and prints the contents of the "WhoAmI.txt" file.
 *
 * Return: Always returns 0.
 */
int WhoAmI(void)
{
    int txt_file, total, read_status;
    size_t letters = 1000;
    char *filename = "WhoAmI.txt";
    char buffer[BUFFERSIZE];

    /* Check if the filename is NULL */
    if (filename == NULL)
        return (0);

    /* Open the "WhoAmI.txt" file in read-only mode */
    txt_file = open(filename, O_RDONLY);
    if (txt_file == -1)
    {
        /* Return 0 if the file cannot be opened */
        return (0);
    }

    total = 0;
    read_status = 1;

    /* Read and print the file contents in chunks */
    while (letters > BUFFERSIZE && read_status != 0)
    {
        read_status = read(txt_file, buffer, BUFFERSIZE);
        write(STDOUT_FILENO, buffer, read_status);
        total += read_status;
        letters -= BUFFERSIZE;
    }

    /* Read and print any remaining content */
    read_status = read(txt_file, buffer, letters);
    write(STDOUT_FILENO, buffer, read_status);
    total += read_status;

    /* Close the file */
    close(txt_file);

    /* Always return 0 */
    return (0);
}

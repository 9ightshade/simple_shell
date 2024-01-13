#include "shell.h"

/**
 * _realloc - Reallocating space for a memory block
 * @ptr: Pointer passed in
 * @old_size: Old size of the array
 * @new_size: New size of the array
 * Return: New pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    /* Pointer to the new memory block */
    void *new_pointer;

    /* Index for copying elements from old to new memory block */
    unsigned int i = 0;

    /* If the old size is equal to the new size, no need to reallocate */
    if (old_size == new_size)
        return (ptr);

    /* If new size is 0 and the pointer is not NULL, free the memory */
    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }

    /* Allocate memory for the new memory block */
    new_pointer = malloc(new_size);

    /* Check if memory allocation was successful */
    if (new_pointer == NULL)
        return (NULL);

    /* Copy elements from the old block to the new block */
    while (i < old_size)
    {
        *((char *)new_pointer + i) = *((char *)ptr + i);
        i++;
    }

    /* Free the old memory block */
    free(ptr);

    /* Return the pointer to the new memory block */
    return (new_pointer);
}

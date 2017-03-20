#include "sotool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (*printer_t) (const char *);

void auto_free(char ** ptrptr)
{
    if (*ptrptr)
    {
        printf("auto_free_called");
        free(*ptrptr);
        *ptrptr = NULL;
    }
}

#define SLOPPY_BUFSZ 512

void sloppy_function(int n)
{
    _on_end_scope_(auto_free) char * buffer;

    buffer = (char *) malloc(SLOPPY_BUFSZ);

    memset(buffer, 0, SLOPPY_BUFSZ);

    sprintf(buffer, "Call number %d\n", n);

    puts(buffer);
}

int main(void)
{
    printer_t   my_printer;
    int         i;

    my_printer = lambda(void,
        (const char * word)
        {
            printf("%s\n", word);
        }
    );

    my_printer("Hello World");

    for (i = 0; i < 5; i++)
    {
        sloppy_function(i+1);
    }

    return 0;
}

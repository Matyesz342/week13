#include "stringutils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void my_tolower(char text[])
{
    int hossz = strlen(text);
    for (int i = 0; i < hossz; i++)
    {
        text[i] = tolower(text[i]);
    }
    
}

int strcmpi(const char *s, const char *t)
{
    char *p1 = strdup(s);
    char *p2 = strdup(t);

    my_tolower(p1);
    my_tolower(p2);

    int result = strcmp(p1, p2);

    free(p1);
    free(p2);

    return result;
}
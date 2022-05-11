#include <stdio.h>
#include <string.h>
#include "prog1.h"
#include <stdlib.h>

#define MAX_LENGTH 256

int pti(const char *elem)
{
    if (strlen(elem) == 3)
    {
        return 1;
    }
    return 0;
}

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        puts("Hiba! Nem adott meg egy szoveges allomanyt!\n");
        exit(1);
    }
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Nem sikerult megnyitni a %s nevu fajlt!\n", filename);
        return 1;
    }
    char buffer[MAX_LENGTH];
    int i = 0;
    char *ptr;
    char *nagytomb = NULL;
    char *nevek = NULL;
    char *eletkor = NULL;
    char *szak = NULL;
    while (fgets(buffer, MAX_LENGTH, fp))
    {
        nagytomb = realloc(nagytomb, (i+1) * sizeof(char));
        nevek = realloc(nevek, (i+1) * sizeof(char));
        eletkor = realloc(eletkor, (i+1) * sizeof(char));
        szak = realloc(szak, (i+1) * sizeof(char));
        nagytomb[i] = atoi(buffer);
        memcpy(nevek, nagytomb, sizeof(char));
        memcpy(eletkor, nagytomb+1, sizeof(char));
        memcpy(szak, nagytomb+2, sizeof(char));
        i++;
        
    }
    fclose(fp);
    char *szaknev = NULL;
    for (int j = 0; j < i; j++)
    {
        if (pti(szak[j]))
        {
            szaknev = realloc(szaknev, (j+1) * sizeof(char));
            szaknev[j] = nevek[j];
        }
    }
    
    
    
    return 0;
}
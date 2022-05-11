#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringutils.h"


#define MAX 100
#define BUFSIZE 100

typedef char * string;

typedef struct {
    char name[20];
    int kor;
    char szak[5];
} Hallgato;

int feltolt(const char* fname, int n, Hallgato tomb[]) 
{
    int index = 0;
    FILE *fp = fopen(fname, "r");
    char line[BUFSIZE];
    char *p;

    string nev;
    int kor;
    string szak;

    while (fgets(line, BUFSIZE, fp)!= NULL)
    {
        line[strlen(line)-1] = '\0';

        p = strtok(line, ",");
        nev = p;
        p = strtok(NULL, ",");
        kor = atoi(p);
        p = strtok(NULL, ",");
        szak = p;

        if(strcmpi(szak, "pti") == 0)
        {
            Hallgato h;
            strcpy(h.name, nev);
            h.kor = kor;
            strcpy(h.szak, szak);
           tomb[index++] = h;
        }
    }
    fclose(fp);
    return index;
}

void print_hallgato(Hallgato h)
{
    printf("%s %d %s\n", h.name, h.kor, h.szak);
}

int cmp(const void *bal, const void *jobb)
{
    const Hallgato *a = bal, *b = jobb;
    return strcmp(a->name,b->name);
}

int main()
{
    const char* fname = "nevek.csv";

    Hallgato tomb[MAX];
    int elemszam = feltolt(fname, MAX, tomb);

    //printf("%d\n", elemszam);

    for (int i = 0; i < elemszam; i++)
    {
        print_hallgato(tomb[i]);
    }
    puts("------------------------------------------------");
    qsort(tomb, elemszam, sizeof(Hallgato), cmp);    

    for (int i = 0; i < elemszam; i++)
    {
        print_hallgato(tomb[i]);
    }

    return 0;
}
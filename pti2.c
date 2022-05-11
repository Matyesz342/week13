#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 2000
#define MULTIPLIER 1.5

typedef struct
{
    int *szamok;
    int elemszam;
    int capacity;
}DynArray;

DynArray * da_create()
{
    DynArray *result=malloc(sizeof(DynArray));
    if(result==NULL)
    {
        exit(2);
    }

    int initial_capacity=20;

    result->szamok=malloc(initial_capacity*sizeof(int));
    if(result->szamok==NULL)
    {
        exit(2);
    }
    result->elemszam=0;
    result->capacity=initial_capacity;
    return result;
}

/*void da_append(DynArray *self, int data)
{
    if(self->elemszam==self->capacity)
    {
        int new_capacity=(int)(MULTIPLIER*self->capacity);
        self->szamok=realloc(self->szamok, new_capacity*sizeof(int));
        if(self->szamok==NULL)
        {
            exit(2);
        }
        self->capacity=new_capacity;
    }
    self->szamok[self->elemszam]=data;
    self->elemszam++;
}
*/

void da_destroy(DynArray *self)
{
    free(self->szamok);
    free(self);
}

int pti(const int n, const int tomb[])
{
   if (tomb[n] == 'i' || tomb[n] == 'I')
    {
        if (tomb[n-1] == 't' || tomb[n-1] == 'T')
        {
            if (tomb[n-2] == 'p' || tomb[n-2] == 'P')
            {
                return true;
            }
            
        }
        
    }
    else
    {
        return false;
    }
}

int main()
{
    char* fajlnev="numbers.txt";
    char szam[MAX];
    int darab = 0;
    char *ptr;

    FILE *fp=fopen(fajlnev,"r");

    if(fp==NULL)
    {
        printf("Hiba tortent  a %s nevu fajl megnyitasakor!\n",fajlnev);
        exit(1);
    }

    DynArray *li=da_create();

    while(fgets(szam, MAX, fp)!=NULL)
    {
        szam[strlen(szam)-1]='\0';
        darab++;
        //da_append(li,atoi(szam));
    }
    int n;
    int pti_darab=0;
    char tomb[darab];
    for (int i = 0; i < darab; i++)
    {
        n = strlen(szam[i]);
        if (pti(n, szam[i]))
        { 
            tomb[i] = strtok(szam[i], ",");
            pti_darab++;
        }
    }
    
    for (int i = 0; i < pti_darab; i++)
    {
        printf("%c\n",tomb[i]);
    }
    

    da_destroy(li);

    fclose(fp);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void tomb_kiir(int meret, double tomb[])
{
    for (int i = 0; i < meret; i++)
    {
        printf("\t%lf", tomb[i]);
    }
    puts("");

}
/*
     ha bal < jobb akkor egy negatív értéket kell visszaadni  
    ha bal == jobb akkor return 0
    ha jobb > bal akkor pozitiv erteket ad vissza
*/



int cmp(const void *bal, const void *jobb)
{
    const double *a = bal, *b = jobb;
    if (*a - *b < 0)
    {
        return -1;
    }
    else if (*a - *b > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    double szamok[] = {2.5, 54.23, 63.65, 12.10, 87.54};
    int meret = sizeof(szamok)/sizeof(szamok[0]);

    tomb_kiir(meret, szamok);

    qsort(szamok, meret, sizeof(double), cmp);

    tomb_kiir(meret, szamok);

    return 0;
}
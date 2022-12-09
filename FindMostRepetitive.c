#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

int validatingArray(int num)
{
    if (num < 0 || num > CAPACITY)
    {
        printf("Number is too big/small! Manually change the capacity of an array!\n");
        exit(1);
    }
}
void cleanBuffer()
{
    printf("bad validation\n");
    while (getchar() != '\n')
        ;
}
void Testvalidation(int *num, int *okay)
{
    printf("enter integer number: ");
    if (scanf("%d", num) && getchar() == '\n')
    {
        ++*okay;
    }
    else
    {
        cleanBuffer();
    }
}
int findmax(int copnum, int numarray[])
{
    int mostre, count = 0, max = 0;
    for (int i = 0; i < copnum; i++)
    {
        count = 0;
        for (int j = i + 1; j < copnum; j++)
        {
            if (numarray[i] == numarray[j])
                ++count;
        }
        if (count >= max)
        {
            max = count;
            mostre = numarray[i];
        }
    }
    return mostre;
}
int main()
{
    int num, okay = 0, copnum;
    int numarray[CAPACITY];

    while (okay == 0)
    {
        Testvalidation(&num, &okay);

        validatingArray(num);
    }
    copnum = num;
    for (int i = 0; i < copnum; i++)
    {
        okay = 0;
        Testvalidation(&num, &okay);
        if (okay == 0)
            --i;
        else
            numarray[i] = num;
    }

   printf("the most frequently recurring number is: %d", findmax(copnum, numarray));

    return 0;
}
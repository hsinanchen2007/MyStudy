```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int* distributeCandies(int candies, int num_people, int* returnSize)
{
    int  idx;
    int* res = malloc(num_people * sizeof(int));
    memset(res, 0, sizeof(int) * num_people);

    for(int i = 0; candies > 0; i++)
    {
        idx = (i % num_people);

        if(candies > i)
            res[idx] = res[idx] + i + 1;
        else
            res[idx] = res[idx] + candies;

        candies = candies - (i + 1);
    }

    *returnSize = num_people;
    return res;
}

int main(void)
{
    int* r;
    int  len;

    r = distributeCandies(10, 3, &len);

    for(int i = 0; i < len; i++)
    {
        printf("%d\t", r[i]);
    }
    printf("\n");

    r = distributeCandies(11, 3, &len);

    for(int i = 0; i < len; i++)
    {
        printf("%d\t", r[i]);
    }
    return 0;
}

```
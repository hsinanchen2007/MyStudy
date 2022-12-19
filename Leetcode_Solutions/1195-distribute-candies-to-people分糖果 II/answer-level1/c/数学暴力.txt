```
#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize)
{
    int i = 0;
    int start = num_people * (num_people + 1) / 2;
    int addition = start;
    int plus = num_people * num_people;
    int sum = 0;

    for (i = 0; sum < candies; i++) {
        sum += addition;
        addition += plus;
    }

    int job = i - 1;

    int *res = malloc(sizeof(int) * num_people);
    if (sum == candies) {
        res[0] = job * (job + 1) * num_people / 2 + (job + 1);
        for (i = 1; i < num_people; i++) {
            res[i] = res[i - 1] + (job + 1);
        }
    } else {
        job = job - 1;
        res[0] = job * (job + 1) * num_people / 2 + (job + 1);
        candies -= res[0];
        for (i = 1; i < num_people; i++) {
            res[i] = res[i - 1] + (job + 1);
            candies -= res[i];
        }

        i = 0;
        job++;
        addition = job * num_people + 1;
        while (candies > 0) {
            res[i] += addition;
            candies -= addition;
            addition++;
            i++;
        }
        res[i - 1] += candies;
    }

    *returnSize = num_people;
    return res;
}


```

```
int* distributeCandies(int candies, int num_people, int* returnSize)
{
    int *ret = malloc(sizeof(int) * num_people);
    memset(ret, 0, sizeof(int) * num_people);
    *returnSize = num_people;

    for(int i = 0; candies > 0; i++)
    {
        int people = i % num_people;
        int candy = candies > (i + 1) ? (i + 1) : candies;
        candies -= candy;
        ret[people] += candy;
    }

    return ret;
}
```

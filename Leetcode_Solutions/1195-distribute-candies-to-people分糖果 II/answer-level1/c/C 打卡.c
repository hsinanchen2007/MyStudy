### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize)
{
    int* pret = (int*)malloc(sizeof(int) * num_people);
    int i;
    int curr = 0;
    int give = 0;
    for (i = 0; i < num_people; i++) {
        pret[i] = 0;
    }

    while (candies != 0) {
        give++;
        if (give > candies) {
            pret[curr] += candies;
            candies = 0;
            break;
        } else {
            pret[curr] += give;
            candies -= give;
            
        }
        curr = (curr + 1) % num_people;
    }

    *returnSize = num_people;
    return pret;
}
```
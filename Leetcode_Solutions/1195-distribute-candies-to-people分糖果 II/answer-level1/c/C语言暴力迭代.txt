### 解题思路
直接上代码

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize = num_people;
    int *ret = (int *)malloc(sizeof(int) * (*returnSize));
    memset(ret, 0, sizeof(int) * (*returnSize));
    int index = 0;
    int current = 1;
    while(candies > 0) {
        if (candies > current) {
            ret[index] += current;
            candies -= current;
        } else {
            ret[index] += candies;
            candies = 0;
        }
        index = (index + 1) % num_people;
        current++; 
    }
    return ret;
}
```
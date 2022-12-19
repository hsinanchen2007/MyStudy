### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int i;
    int count = 1;
    int *res = malloc(sizeof(int) * num_people);
    for (i = 0; i < num_people; i++) {
        res[i] = 0;
    }
    
    /* 给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推.... */
    while (candies > count) {
        res[(count - 1) % num_people] += count;
        candies -= count;
        count++;
    }

    /* 剩下糖果数不够, 全部发给当前的小朋友 */
    res[(count - 1) % num_people] += candies;

    *returnSize = num_people;

    return res;
}
```
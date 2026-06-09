### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int* ans = (int *)malloc(num_people*sizeof(int));
    memset(ans, 0, sizeof(int)*num_people);
    int i = 0, j = 0;
    while(candies > 0){
        if(candies > i+j*num_people){
            ans[i] = ans[i] + i + j*num_people + 1;
            candies = candies - i - j*num_people - 1;
        }
        else{
            ans[i] += candies;
            candies = 0;
        }
        i++;
        if(i == num_people){
            i = 0;
            j++;
        }
    }
    *returnSize = num_people;
    return ans;
}
```
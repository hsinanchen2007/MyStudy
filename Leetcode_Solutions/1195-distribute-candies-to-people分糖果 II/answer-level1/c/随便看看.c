### 解题思路
让i同时兼职当前糖果数与当前小孩序号。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int *ans=(int *)malloc(sizeof(int)*num_people);
    int i=0;
    for(int i=0;i<num_people;i++){
        ans[i]=0;
    }
    while (candies != 0) {
            ans[i % num_people] += candies<i+1?candies:i+1;
            candies -= candies<i+1?candies:i+1;
            i++;
    }
    *returnSize=num_people;
    return ans;
}

```
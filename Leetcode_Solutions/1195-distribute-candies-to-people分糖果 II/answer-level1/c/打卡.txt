### 解题思路
暴力方法

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MIN(x,y) ((x)<(y))?(x):(y)
#define MAX_PEOPLE 1010
int nums[MAX_PEOPLE];
int* distributeCandies(int candies, int num_people, int* returnSize){
    memset(nums,0 ,MAX_PEOPLE*sizeof(int));
    if(candies<1  || num_people<1) {
        *returnSize = num_people;
        return nums;
    }
    int k=0;
    while(candies!=0){
 
        nums[k % num_people]+=MIN(k+1, candies);
        candies -= MIN(k+1, candies);
        k++;

    }
    *returnSize = num_people;
    return nums;
}
```
### 解题思路
求组合中最小的里面，和是最大的，可以认为排序后，为了保护后边次大的不成为组合里较大的，那么损失最小的就是按照顺序组合。
先排序，后加和。


### 代码

```c
int cmp(const void* a, const void* b) 
{   
    if (*((int *)a) > *((int *)b)) {
        return 1;
    } else if (*((int *)a) < *((int *)b))
    {
        return -1;
    } else {
        return 0;
    }
}

int arrayPairSum(int* nums, int numsSize){

    if (numsSize < 1) {
        return 0;
    }
    if (nums == NULL) {
        return 0;
    }
    //先排序
    qsort(nums, numsSize, sizeof(int), cmp);
    //取奇数的数字累加
    int sum = 0;
    for(int i; i < numsSize - 1; i = i + 2) {
        sum = sum + nums[i];
    }
    return sum;

}
```
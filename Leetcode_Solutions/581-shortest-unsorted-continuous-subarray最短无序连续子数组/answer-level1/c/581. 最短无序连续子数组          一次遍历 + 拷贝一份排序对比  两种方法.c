### 解题思路
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。


### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int cmp (const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int findUnsortedSubarray(int* nums, int numsSize){
#if 0
    int i,j, l =0, r = numsSize - 1, min = nums[numsSize-1], max = nums[0];

    if(numsSize <= 1)   return 0;

    for (i=1;i<numsSize;i++){
        max = MAX(max, nums[i]);
        min = MIN(min, nums[numsSize-1-i]);
        if(nums[i] < max) l = i;
        if(nums[numsSize - 1 - i] > min) r = numsSize - 1 -i;
    }
    return l > r? l - r + 1 : 0;
#else
    int *backup = malloc(numsSize * sizeof(int)),i,l=0,r=0;
    memcpy(backup, nums, numsSize * sizeof(int));

    qsort(backup, numsSize, sizeof(int), cmp);
    for(i=0; i < numsSize; i++) {
        //printf("%d bakcupi=%d\n",i, backup[i]);
        if(nums[i] != backup[i]){
            l = i;
            break;
        }
    }
    for (i=numsSize-1; i >= 0; i--){
        if(nums[i] != backup[i]){
            r = i;
            break;
        }
    }

    return l == r ? 0 : (r - l + 1);

#endif
}
```
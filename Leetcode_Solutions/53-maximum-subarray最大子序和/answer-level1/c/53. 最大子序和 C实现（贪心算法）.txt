### 解题思路
此处撰写解题思路

### 代码

```c
inline int Max(int a, int b)
{
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    if (!nums) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    int curSumMax = nums[0];
    int sumMax = nums[0];
    for (int i = 1; i < numsSize; i++) {
        curSumMax = Max(nums[i], curSumMax + nums[i]);
        sumMax = Max(sumMax, curSumMax);
    }
    return sumMax;
}



```
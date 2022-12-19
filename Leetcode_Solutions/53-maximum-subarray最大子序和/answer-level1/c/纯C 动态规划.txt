### 解题思路
动态规划 清清爽爽

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int index = 0;
    int max = nums[0];
    dp[0] = nums[0];
    
    for (index = 1; index <= numsSize - 1; index++)
    {
        if (0 < dp[index - 1])
        {
            dp[index] = nums[index] + dp[index - 1];
        }
        else
        {
            dp[index] = nums[index];
        }

        max = dp[index] > max ? dp[index] : max;
    }

    return max;
}
```
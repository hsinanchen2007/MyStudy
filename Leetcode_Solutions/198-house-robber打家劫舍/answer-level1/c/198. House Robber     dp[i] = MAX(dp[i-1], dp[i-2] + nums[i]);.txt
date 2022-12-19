### 解题思路

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。



### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
int rob(int* nums, int numsSize){
    int i, max = 0;
    int *dp = malloc(numsSize * sizeof(int));

    if (numsSize == 0)
        return 0;
    
    if (numsSize == 1)
        return nums[0];

    if (numsSize == 2)
        return MAX(nums[0], nums[1]);

    dp[0] = nums[0];
    dp[1] = MAX(nums[0],nums[1]);
    for (i = 2; i < numsSize; i++) {
        dp[i] = MAX(dp[i-1], dp[i-2] + nums[i]);
        max = MAX(max, dp[i]);
    }
    return max;
}
```
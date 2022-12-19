# 思路
首先将题目翻译一遍，就是在一串正整数中寻找是否有和为一个整数（就是题目数组的和的一半）的若干个数字

发现此题和01背包问题很相似，由此用动态规划来求解。
申请一个二维数组，dp[i][j], 表示从下表0到i中取若干个数字，使这些数字之和为j。

当遇到一个nums[i]时，有两种情况，一种是选取nums[i]，一种是不选，
    当选择时，dp[i][j] = dp[i-1][j-nums[i]]
    不选择时，dp[i][j] = dp[i-1][j];保持原状


```
bool canPartition(int* nums, int numsSize){
    int sum = 0;
    int i = 0;
    int j = 0;
    
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2 == 0) {
        sum = sum / 2;
    } else {
        return false;
    }
    
    char **dp = (char **)calloc(numsSize,sizeof(char*));
    for (i = 0; i < numsSize; i++) {
        dp[i] = (char *)calloc(sum+1, sizeof(char));
    }
    
    for (i = 1; i <= sum; i++) {
        dp[0][i] = nums[0] == i ? 1 : 0;
    }
    for (i = 0; i < numsSize; i++) {
        dp[i][0] = 1;
    }
    
    for (i = 1; i < numsSize; i++) {
        for (j = 1; j <= sum; j++) {
            if (j >= nums[i]) {
                dp[i][j] =  dp[i-1][j] || dp[i-1][j-nums[i]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[numsSize-1][sum] == 1 ? true : false;
}
```

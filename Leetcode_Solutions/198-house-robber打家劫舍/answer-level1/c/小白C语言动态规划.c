//最后一步： 窃贼的最优策略中，有可能偷或者不偷最后一栋N-1；
//子问题： 窃贼在前i栋房子中最多偷多少金币
//状态转移方程： dp[i] = max(dp[i-1],dp[i-2] + nums[i-1]);
int max(int a, int b)
{
    return a > b ? a : b;
}
int rob(int* nums, int numsSize)
{
    int n = numsSize;
    int i;
    if (n == 0)
    return 0;
    int* dp = (int*)malloc((n+1)*sizeof(int));
    dp[0] = 0;
    dp[1] = nums[0];
    for (i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i-1],(dp[i-2] + nums[i-1]));
    }
    return dp[n];
}
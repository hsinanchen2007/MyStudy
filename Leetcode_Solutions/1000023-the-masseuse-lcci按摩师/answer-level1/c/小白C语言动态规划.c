//dp[i]定义： 表示按摩前i名顾客（0 ... i - 1)的最佳总利润
//最后一步： 选择按摩第N - 1名顾客，或者不按摩 (开二维动态数组，dp[i][0]表示按摩，dp[i][1]表示不按摩)
//子问题： （按摩第i - 1，则第i - 2名不按摩 ）与（不按i - 1，按i - 2）
//状态转移方程： dp[i] = max(dp[i-1], (dp[i-2]+num[i-1])
int max(int a, int b)
{
    return a > b ? a : b;
}
int massage(int* nums, int numsSize)
{
    int n = numsSize;
    int* dp = (int*)malloc((n + 1)*sizeof(int));
    if (n == 1)
    return nums[0];
    if (n == 0)
    return 0;
    dp[0] = 0;
    dp[1] = nums[0];
    dp[2] = nums[1];
    int i;
    for (i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i-1], (dp[i-2] + nums[i-1]));
    }
    return dp[n];
}
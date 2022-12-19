//没太明白为什么1和2的情况要单独讨论
//定义dp[i]: 跳到第i阶有多少中方式
//最后一步： 有多少种方式跳到第N阶
//子问题： 跳到N - 1, N - 2, N - 3阶分别有多少种方式
//状态转移方程： dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
//初始化： dp[1] = 1; dp[2] = 2; dp[3] = 3;
int waysToStep(int n)
{
    if (n == 1)
    return 1;
    if (n == 2)
    return 2;
    long* dp = (long*)malloc((n+1)*sizeof(long));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000007;
    }
    return dp[n];
}
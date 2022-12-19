//最后一步： 加上j²后, 构成最优策略解
//状态： dp[i] = 构成 i 的最少（最优）的平方数个数
//子问题： 构成i的最少平方数的个数是多少个；
//转移方程： dp[i] = min((1 <= j * j <= i) dp[i-j²] + 1)
int MIN(int a, int b)
{
    return a < b ? a : b;
}
int numSquares(int n)
{
    int i, j;
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 0; //初始化（虽然不正确，正整数不包括0，但方便理解）当正整数 == 0时， 构成0的完全平方和个数为0；
    for (i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for(j = 1; j*j <= i; j++)
        {
            dp[i]= MIN(dp[i],(dp[i-(j*j)] + 1));
        }
    }
    return dp[n];
}
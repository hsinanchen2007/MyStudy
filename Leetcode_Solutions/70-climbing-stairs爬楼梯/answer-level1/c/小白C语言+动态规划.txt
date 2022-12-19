![kk.png](https://pic.leetcode-cn.com/eabeff614d948c3f88f6e2cf1a583da08218b43d4289fd7ee66726aa0d04eb75-kk.png)


//最后一步： （由（n-1）阶一步爬到第n阶 || 由（n-2）阶两步爬到第n阶）
//子问题： 爬到n-1阶 && 爬到n-2阶分别有多少种方法，
//方法总数 = 爬（n-1）法 + 爬（n-2）法；
//注： 给定n是一个正整数；
//转移方程： dp[n] = dp[n-1] + dp[n-2];
//初始化： dp[1] = 1; dp[2] = 2;
int climbStairs(int n)
{
    if (n == 1)
    return 1;
    int* dp = (int*)malloc((n + 1)*sizeof(int));
    dp[1] = 1;
    dp[2] = 2;
    int i;
    for (i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
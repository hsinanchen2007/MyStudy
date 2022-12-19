# 动态规划：

1. 状态：dp[i, j] => i 代表房屋，j 代表状态：0 不偷、1 偷， dp[i,j]
2. 状态转移方程：
    选择不偷： 那么最高金额有两种情况, 昨天也没偷 或者 昨天偷了
    dp[i, 0] = Math.Max(dp[i - 1, 0], dp[i - 1, 1]);
    选择偷：那么只能来自 昨天不偷
    dp[i, 1] = dp[i - 1, 0] + nums[i];
3. 初始化
    初始化第一天偷 或者 不偷 的情况
    dp[0, 0] = 0;
    dp[0, 1] = nums[0];

# C#代码

```csharp
public int Rob(int[] nums)
{
    int n = nums.Length;
    if (n == 0) return 0;

    int[,] dp = new int[n, 2];
    // 初始化第一天偷 与 不偷的情况
    dp[0, 0] = 0;
    dp[0, 1] = nums[0];

    for (int i = 1; i < n; i++)
    {
        // 选择不偷： 那么最高金额有两种情况, 昨天也没偷 或者 昨天偷了
        dp[i, 0] = Math.Max(dp[i - 1, 0], dp[i - 1, 1]);
        // 选择偷：那么只能来自 昨天不偷
        dp[i, 1] = dp[i - 1, 0] + nums[i];
    }

    return Math.Max(dp[n - 1, 0], dp[n - 1, 1]);
}
```

# 优化空间复杂度

```csharp
public int Rob_O(int[] nums)
{
    int n = nums.Length;
    if (n == 0) return 0;

    // 初始化
    int dp_0 = 0;
    int dp_1 = nums[0];

    int temp;

    for (int i = 1; i < n; i++)
    {
        temp = dp_0;
        dp_0 = Math.Max(temp, dp_1);
        dp_1 = temp + nums[i];
    }

    return Math.Max(dp_0, dp_1);
}
```
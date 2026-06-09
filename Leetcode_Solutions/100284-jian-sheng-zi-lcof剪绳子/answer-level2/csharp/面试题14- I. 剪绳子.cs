### 解题思路
动态规划 + 数学分析

### 代码
# 动态规划法
```csharp
public class Solution {
    public int CuttingRope(int n) {
        if (n < 0) return 0;
        if (n < 5) return new[] { 1, 1, 1, 2, 4 }[n];

        var dp = new int[n + 1];
        // 0~4 长度的绳子剪出来的长度 0、0、1、2、4，不使用DP反而可以得到更大的结果
        for (int index = 0; index < 5; index++)
            dp[index] = index;

        for (int index = 5; index <= n; index++)
        {
            dp[index] = Enumerable
                .Range(2, index / 2 - 1)
                .Select(value => dp[value] * dp[index - value])
                .Max();
        }

        return dp[n];
    }
}
```

# 数学分析法
```
if (n <= 3) return n - 1;
int times = n / 3, remainder = n % 3;
switch (remainder)
{
    case 0:
        {
            // 优先分拆为 3
            return (int)Math.Pow(3, times);
        }
    case 1:
        {
            // 剩余 1 时，和其中一个 3 合并为 4
            return (int)Math.Pow(3, times - 1) * 4;
        }
    case 2:
        {
            // 剩余 2 时直接相乘
            return (int)Math.Pow(3, times) * 2;
        }
    default:
        throw new NotImplementedException();
}
```
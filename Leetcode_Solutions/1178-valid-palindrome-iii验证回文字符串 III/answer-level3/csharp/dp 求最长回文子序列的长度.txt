思路：求最长回文**子序列**的长度，如果可删除字符数小于字符串长度与最长回文**子序列**的长度之差了，那么无论怎么删都不可能。

```c#
public class Solution
{
    public bool IsValidPalindrome(string s, int k)
    {
        int[,] dp = new int[s.Length, s.Length];

        int n = s.Length;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i, j] = 1;
            }
        }

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (s[j] == s[i])
                {
                    if (j - i > 1)
                    {
                        dp[i, j] = dp[i + 1, j - 1] + 2;
                    }
                    else
                    {
                        dp[i, j] = 2;
                    }
                }
                else
                {
                    dp[i, j] = Math.Max(dp[i + 1, j], dp[i, j - 1]);
                }
            }
        }
        return dp[0, n - 1] >= (n - k);
    }
}
```
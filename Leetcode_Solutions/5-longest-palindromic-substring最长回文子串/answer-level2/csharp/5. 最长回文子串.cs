### 解题思路
动态规划算法
bool[,] dp[start, end] 表示从i到j的字符串是否为回文；

### 代码

```csharp
public class Solution {
    public string LongestPalindrome(string s) {
        if (string.IsNullOrEmpty(s)) return string.Empty;
        var dp = new bool[s.Length, s.Length];
        int index = 0;
        for (; index < s.Length; index++)
        {
            dp[index, index] = true;
        }

        int length = 1; index = 0;
        for (int end = 1; end < s.Length; end++)
        {
            for (int start = end - 1; start >= 0; start--)
            {
                dp[start, end] = end - start <= 1 ?
                    s[start] == s[end] :
                    dp[start + 1, end - 1] && s[start] == s[end];

                if (dp[start, end] && end - start + 1 > length)
                {
                    length = end - start + 1;
                    index = start;
                }
            }
        }
        return s.Substring(index, length);
    }
}
```
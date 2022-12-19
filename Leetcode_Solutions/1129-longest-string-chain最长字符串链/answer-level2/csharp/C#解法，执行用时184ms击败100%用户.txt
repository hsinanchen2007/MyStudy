### 解题思路
动态规划解法。

最后结果：
执行用时 :184 ms, 在所有 C# 提交中击败了100.00%的用户
内存消耗 :26.7 MB, 在所有 C# 提交中击败了50.00%的用户


该问题可以分解为两个子问题，
1. 最长递增序列（动态规划）
2. 判断字符串前身（IsPrevious函数）

具体解法如下：

### 代码

```csharp
public class Solution
{
    private bool IsPrevious(string a, string b)
    {
        if (a.Length != b.Length - 1)
        {
            return false;
        }
        int i = 0;
        int j = 0;
        int diff = 0;

        while (i < a.Length)
        {
            if (a[i] == b[j])
            {
                i++; j++;
                continue;
            }
            j++;
            diff++;
            if (diff > 1)
            {
                return false;
            }
        }
        return true;
    }

    public int LongestStrChain(string[] words)
    {
        if (words == null || words.Length == 0)
        {
            return 0;
        }
        if (words.Length == 1)
        {
            return 1;
        }

        words = words.OrderBy(a => a.Length).ToArray();
        int[] dp = new int[words.Length];
        int[] prev = new int[words.Length];
        for (int i = 0; i < words.Length; i++)
        {
            prev[i] = -1;
        }
        dp[0] = 1;
        for (int i = 1; i < words.Length; i++)
        {
            int max = -1;
            string target = words[i];
            for (int j = i - 1; j >= 0; j--)
            {
                string preword = words[j];
                if (IsPrevious(preword, target))
                {
                    if (dp[j] < max)
                    {
                        continue;
                    }
                    max = j;
                }
            }
            if (max >= 0)
            {
                dp[i] = dp[max] + 1;
                prev[i] = max;
            }
            else
            {
                dp[i] = 1;
            }
        }
        int maxVal = 0;
        int maxIndex = -1;
        for (int i = 0; i < words.Length; i++)
        {
            if (dp[i] > maxVal)
            {
                maxVal = dp[i];
                maxIndex = i;
            }
        }
        int i1 = maxIndex;
        while (i1 >= 0)
        {
            Console.WriteLine(words[i1]);
            i1 = prev[i1];
        }
        return maxVal;
    }
}
```
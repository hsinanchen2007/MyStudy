### 解题思路
动态规划：dp(x)为从字符串子串为结果的最大索引，所以最后只需要判断最大索引是否==字符串长度-1即可。

### 代码

```csharp
public class Solution {
    public bool WordBreak(string s, IList<string> wordDict)
        {
            int[] result = new int[s.Length];
            if (wordDict.Contains(s[0].ToString()))
            {
                result[0] = 0;
            }
            else
            {
                result[0] = -1;
            }

            for (int i = 1; i < result.Length; i++)
            {
                for (int j = i; j >= 1; j--)
                {
                    if (wordDict.Contains(s.Substring(j, i - j + 1)) && result[j - 1] == j - 1)
                    {
                        result[i] = i;
                        break;
                    }
                }
                if (result[i] != i)
                {
                    if (wordDict.Contains(s.Substring(0, i + 1)))
                    {
                        result[i] = i;
                    }
                    else
                    {
                        result[i] = result[i - 1];
                    }
                }
            }

            if (result.Last() == result.Length - 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
}
```
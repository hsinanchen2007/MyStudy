### 解题思路
从最大子串依次搜索！

### 代码

```csharp
public class Solution {
    public string LongestPalindrome(string s) {
        if (s.Length < 2) return s;
        for (int i = s.Length - 1; ; i--)
            for (int k = 0; k + i < s.Length; k++)
                for (int m = k, n = k + i; s[m] == s[n];)
                    if (m++ + 3 > n--) return s.Substring(k, ++i);
    }
}
```
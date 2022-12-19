### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MaxLength(IList<string> s) {
        int x = 0;
        H(s, new bool[26], 0, 0, ref x);
        return x;
    }
    static void H(IList<string> s, bool[] dp, int index, int x, ref int res)
    {
        if (index == s.Count) res = Math.Max(res, x);
        else{
            string temp = s[index];
            int i = 0;
            while (i < temp.Length && !dp[temp[i] - 'a']) dp[temp[i++] - 'a'] = true;
            if (i == temp.Length) H(s, dp, index + 1, x + temp.Length, ref res);
            while (--i >= 0) dp[temp[i] - 'a'] = false;
            H(s, dp, index + 1, x, ref res);
        }
    }
}
```
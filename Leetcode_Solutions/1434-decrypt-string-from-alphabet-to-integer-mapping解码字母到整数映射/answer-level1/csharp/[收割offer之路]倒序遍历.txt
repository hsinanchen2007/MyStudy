### 解题思路
倒序遍历

### 代码

```csharp
public class Solution {
    public string FreqAlphabets(string s)
    {
        string res = "";
        for (int i = s.Length-1; i >=0; i--)
        {
            int cur = 0;
            if (s[i]=='#')
            {
                cur = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                i -= 2;
            }
            else
            {
                cur = s[i] - '0';
            }
            char c = (char)(cur-1 +Convert.ToInt32('a'));
            res = c+res;
        }

        return res;
    }
}
```
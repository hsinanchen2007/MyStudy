### 解题思路
首先编写一个辅助函数，用于判断s的第low+1位到s的high+1位所形成的字符串是否是回文字符串。
然后从s的第一个字符开始，依次找它和后面的字符是否构成回文字符串，用max记录当前找到的最长回文子串长度，用str保存当前找到的最长回文子串。
这个题目有一个坑点，即一个字符形成的回文子串的情况，解决方法可以先将str设置为s的第一个字符。

### 代码

```csharp
public class Solution {
    public string LongestPalindrome(string s) {
        int i, j;
        int max = 0;
        string str = "";
        if (s.Length < 2)
            return s;
        if (IsIt(s,0,s.Length-1))
            return s;
        str = s.Substring(0,1);
        for (i = 0; i < s.Length; i++)
        {
            for (j = i + 1; j < s.Length; j++)
            {
                if (IsIt(s,i,j))
                {
                    if (j - i + 1 > max)
                    {
                        max = j - i + 1;
                        str = s.Substring(i,j - i + 1);
                    }
                }
            }
        }
        return str;
    }
    public bool IsIt(string s, int low, int high)
    {
        for (int i = 0; i <= (high - low) / 2; i++)
        {
            if (s[low + i] != s[high - i])
                return false;
        }
        return true;
    }
}
```
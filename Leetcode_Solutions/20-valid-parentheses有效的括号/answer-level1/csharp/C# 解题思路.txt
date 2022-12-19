### 解题思路
在字符中查找 (),[],{} 这三种字符，如果有就删除。所以循环到最后合适的总会是空字符。
### 代码

```csharp
public class Solution {
    public bool IsValid(string s) {
         if (string.IsNullOrEmpty(s)) return true;
            while (s.Length>1)
            {
                bool startB = false;
                if (s.IndexOf("()") != -1)
                {
                    s = s.Remove(s.IndexOf("()"), 2);
                    startB = true;
                }
                if (s.IndexOf("[]") != -1)
                {
                    s = s.Remove(s.IndexOf("[]"), 2);
                    startB = true;
                }
                if (s.IndexOf("{}") != -1)
                {
                    s = s.Remove(s.IndexOf("{}"), 2);
                    startB = true;
                }

                if (!startB) return false;
            }

            if (string.IsNullOrEmpty(s)) return true; else return false;
    }
}
```
### 解题思路
![image.png](https://pic.leetcode-cn.com/07e2da6dbe6d531040a77d5f13ba728ddcf70f782b7ccf7b63c05a62feb4e41e-image.png)

### 代码

```csharp
public class Solution {
    public char FirstUniqChar(string s) {
        for (int i = 0; i < s.Length; i++)
        {
            if (s.IndexOf(s[i])==i&&s.LastIndexOf(s[i])==i)
            {
                return s[i];
            }
        }

        return ' ';
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int TitleToNumber(string s) {
        int times = 1;
        int res = 0;
        for (int i = s.Length - 1; i >= 0; i--)
        {
            int num = (char)s[i]-64;
            res = res + num * times;
            times *= 26;
        }

        return res;
    }
}
```
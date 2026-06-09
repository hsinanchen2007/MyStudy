### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public string ReverseWords(string s) {
        s = s.Trim();
        StringBuilder result = new StringBuilder();
        int left = s.Length - 1;
        int right = s.Length - 1;
        while(left >= 0)
        {
            while(left >= 0 && s[left] != ' ')
            {
                left--;
            }
            result.Append(s.Substring(left + 1, right - left) + " ");
            while(left > 0 && s[left] == ' ')
            {
                left--;
            }
            right = left;
        }
        return result.ToString().Trim();
    }
}
```
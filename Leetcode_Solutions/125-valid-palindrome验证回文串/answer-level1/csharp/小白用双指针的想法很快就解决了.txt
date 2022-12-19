### 解题思路
此处撰写解题思路
终于独立完成了一道题目，开心哈哈
### 代码

```csharp
public class Solution {
    public bool IsPalindrome(string s) {
        s = s.ToLower().Replace(" ", "");
        int left = 0;
        int right = s.Length - 1;

        while (left <= right)
        {
            if (!Char.IsLetterOrDigit(s[left]))
            {
                left++;
                continue;
            }
            if (!Char.IsLetterOrDigit(s[right]))
            {
                right--;
                continue;
            }

            if(s[right] != s[left])
            {
                return false;
            }

            left++;
            right--;

        }

        return true;
    }
}
```
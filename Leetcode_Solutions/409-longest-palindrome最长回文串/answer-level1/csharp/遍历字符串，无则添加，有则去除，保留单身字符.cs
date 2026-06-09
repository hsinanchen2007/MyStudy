### 解题思路
1. 思路很简单，用一个哈希set保存未能成对的字符，最长回文串可以用成双成对的字符，中间加上至多一个单身的字符（如果单身的字符数大于1，则取1个就行），一旦知道了单身的字符数，成双成对的字符数可以用总数-单身的字符出求得。
1. 遍历每个字符，如果HashSet没有和它一样的，则加入HashSet，如果有一样的，将其从HashSet移除
1. 这样最终保留的就是单身的字符数（成双成对的都已经被移除了）
- 当单身的只有一个时，说明原始字符串本身就可以构成回文串，因为除了单身的那个字符，其余都可以两两组队（`return s.Length;`）
- 当单身的多于1个时，任意取一个单身的即可，也就是说原始字符串去除所有单身的字符，再加上任意一个单身字符，即可组成最长回文串（`return s.Length - charSet.Count + 1;`）

### 代码

```csharp
public class Solution {
    public int LongestPalindrome(string s) {
        HashSet<char> charSet = new HashSet<char>();
        foreach (char c in s)
        {
            if (charSet.Contains(c))
            {
                charSet.Remove(c);
            }
            else
            {
                charSet.Add(c);
            }
        }
        if (charSet.Count > 1)
        {
            return s.Length - charSet.Count + 1;
        }
        return s.Length;
    }
}
```
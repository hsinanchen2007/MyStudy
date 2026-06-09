### 解题思路
思路：可构成的回文长度 = 偶数字符数量 + 一个奇数字符（如果没有奇数字符则为0）
用哈希表存没有遇到过的字符，如果已遇到过该字符就从哈希表里移除，然后长度+2。遍历结束在看看哈希表里面有没有剩余的单个字符，有就+1，返回结果。

### 代码

```csharp
public class Solution {
    public int LongestPalindrome(string s) {
        int len = 0;
        HashSet<char> charSet = new HashSet<char>();
        for (int i = 0; i < s.Length; ++i) {
            char c = s[i];
            if (charSet.Contains(c)) {
                len += 2;
                charSet.Remove(c);
            } else {
                charSet.Add(c);
            }
        }
        if (charSet.Count > 0) {
            ++len;
        }
        return len;
    }
}
```
### 思路：
    
如果原字符串为空字符串，返回原字符串。否则，将原字符串转换为list，令转件后的字符串等于原字符串的第一个字符，设置一个计数器num，用来记录和当前字符相同的字符的数量。当遇到一个不同的字符时，将结果字符串拼接上上一字符的数量，然后在拼接上当前字符。最后返回原字符串和转换后字符串中最短的那个。
```
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return S
        s = list(S)
        n = len(s)
        ans = s[0]
        num = 1
        for i in range(1, n):
            if s[i] != s[i-1]:
                ans += str(num)
                ans += s[i]
                num = 1
            else:
                num += 1
        ans += str(num)
        
        return ans if len(ans) < len(S) else S
```

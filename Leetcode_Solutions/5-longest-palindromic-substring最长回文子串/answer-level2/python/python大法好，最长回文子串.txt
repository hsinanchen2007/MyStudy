### 解题思路
我是这样想的，回文第一个字符和最后一个字符肯定是一样的，就遍历出这样的子串，然后再判断正向和逆向是否一样

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return s

        if len(set(s)) == 1:
            return s
        res = s[0]
        for i in range(len(s)):
            a = s[i]
            for j in range(len(s[i+1:])):
                if a == s[i+j+1]:
                    r = s[i:i+j+2]
                    if len(r) > len(res) and r == r[::-1]:
                        res = r
                        
        return res




```
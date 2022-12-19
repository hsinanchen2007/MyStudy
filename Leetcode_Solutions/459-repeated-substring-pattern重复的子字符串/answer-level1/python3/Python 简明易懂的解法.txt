如果任意长度的子字串能够拼成原字符串，则返回True
否则返回False

```
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for i in range(1,len(s)):
            if s[:i]*(len(s)//i) == s:
                return True
        return False
```

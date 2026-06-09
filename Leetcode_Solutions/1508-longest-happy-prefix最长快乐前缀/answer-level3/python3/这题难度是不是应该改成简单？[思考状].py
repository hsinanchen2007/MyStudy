```
class Solution:
    def longestPrefix(self, s: str) -> str:
        n = len(s)
        if n <= 1:
            return ''
        res = ''
        for i in range(1,n):
            if s[i] == s[0]:
                if s[:n-i] == s[i:]:
                    res = s[:n-i]
                    return res
        return res 
```

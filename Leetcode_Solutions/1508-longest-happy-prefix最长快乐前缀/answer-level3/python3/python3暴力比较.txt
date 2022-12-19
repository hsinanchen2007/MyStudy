```
class Solution:
    def longestPrefix(self, s: str) -> str:
        for i in range(1,len(s)):
            a,b=s[:-i],s[i:]
            if a==b:
                return a
        return ''
```

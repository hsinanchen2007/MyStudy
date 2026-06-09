```
class Solution:
    def longestPrefix(self, s: str) -> str:
        l=len(s)
        if l<2:
            return ""
        for i in range(l-1,-1,-1):
            if s[0:i]==s[l-i:l]:
                return s[0:i]
        return ""
```



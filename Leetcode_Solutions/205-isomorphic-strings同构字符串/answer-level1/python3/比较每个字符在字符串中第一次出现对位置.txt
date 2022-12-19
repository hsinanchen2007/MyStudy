```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            if s.index(s[i]) != t.index(t[i]):
                return False
        return True
```

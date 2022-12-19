```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for i in s:
            if i in t:
                t = t[t.index(i)+1:]
            else:
                return False
        return True
```

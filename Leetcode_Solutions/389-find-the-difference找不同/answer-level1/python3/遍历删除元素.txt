```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        o = list(t)
        for i in s:
            o.remove(i)
        return o[0]
```

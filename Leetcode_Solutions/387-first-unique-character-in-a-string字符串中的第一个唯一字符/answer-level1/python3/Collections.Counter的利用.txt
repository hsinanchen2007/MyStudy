```
class Solution:
    def firstUniqChar(self, s: str) -> int:
        if not s: return -1
        CNT = collections.Counter(s)
        for i,v in enumerate(s):
            if CNT[v] == 1:
                return i
        else:
            return -1
```

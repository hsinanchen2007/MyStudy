```
class Solution:
    def firstUniqChar(self, s: str) -> int:
        c = collections.Counter(list(s))
        for i in range(len(s)):
            if c[s[i]] == 1:
                return i
        return -1
```

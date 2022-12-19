```
class Solution:
    def firstUniqChar(self, s: str) -> int:
        from collections import Counter
        s_counter = Counter(s)
        for i in range(len(s)):
            if s_counter.get(s[i]) == 1:
                return i
        return -1
```

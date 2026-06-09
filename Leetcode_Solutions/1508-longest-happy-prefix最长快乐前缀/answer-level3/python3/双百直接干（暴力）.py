暴力走起来 hhh

```
class Solution:
    def longestPrefix(self, s):
        m = 0
        n = 0
        for i in range(len(s)):
            if s[:i] == s[-i:]:
                if len(s[:i]) > m:
                    m = len(s[:i])
                    n = i
        return s[:n]
```

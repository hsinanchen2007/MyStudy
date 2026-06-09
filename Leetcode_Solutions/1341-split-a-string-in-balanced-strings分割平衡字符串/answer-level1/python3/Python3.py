```
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count = 0
        i = 0
        for j in range(len(s)):
            if s[i:j].count("R") == s[i:j].count("L"):
                count += 1
                i = j
        return count
```


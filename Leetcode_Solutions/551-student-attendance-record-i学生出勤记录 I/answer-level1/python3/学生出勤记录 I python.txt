``` python
class Solution:
    def checkRecord(self, s: str) -> bool:
        if not s:
            return False
        count_A = 0
        for i in range(len(s)):
            if s[i] == 'A' :
                count_A += 1
                if count_A > 1 :
                    return False
            elif s[i] == 'L':
                if (i > 1 and s[i-1] == 'L') and s[i-2] == 'L':
                    return False
        return True
```

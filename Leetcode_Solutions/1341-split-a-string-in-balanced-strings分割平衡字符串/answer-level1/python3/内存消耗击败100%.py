```
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        balance = 0
        res = 0
        for ss in s:
            if ss == 'L':
                balance += 1
            elif ss == 'R':
                balance -= 1
            if balance == 0:
                res += 1
        return res
```

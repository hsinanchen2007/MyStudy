```
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        max_len = len(2*A + B)
        i = 1
        C = A
        while len(C) <= max_len:
            if B in C:
                return i
            else:
                i += 1
                C += A
        return -1
        
```

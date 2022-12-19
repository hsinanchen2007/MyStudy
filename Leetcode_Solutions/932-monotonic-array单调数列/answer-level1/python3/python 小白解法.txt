```
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        set_A = sorted(A)
        if set_A == A or set_A == A[::-1]:
            return True
        else:
            return False
```

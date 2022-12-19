```
class Solution:
    def sumOfDigits(self, A: List[int]) -> int:
        t, c = min(A), 0
        while t != 0:
            c = t % 10 + c
            t = t // 10
        return 1 - c%2
        
```

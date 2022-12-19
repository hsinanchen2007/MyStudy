```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)/3
        s = 0
        count = 0
        for i in range(0, len(A)-1):
            s += A[i]
            if s == total and count == 1:
                return True
            if s == total:
                count += 1
                s = 0
        return False
```

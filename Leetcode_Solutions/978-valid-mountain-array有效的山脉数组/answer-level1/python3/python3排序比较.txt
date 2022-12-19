```
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        a = A.index(max(A))
        if a == 0 or a == len(A) - 1:
            return False
        for i in range(a):
            if A[i] >= A[i+1]:
                return False
        for i in range(a,len(A)-1):
            if A[i] <= A[i+1]:
                return False
        return True
```

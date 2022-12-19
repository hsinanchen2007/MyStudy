```
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        index=0
        for i in range(len(A)-1):
            if A[i]>=A[i+1]:
                index=i
                break
        for i in range(index, len(A)-1):
            if A[i]<=A[i+1]:
                return False
        if index==0 or index==len(A):
            return False
        return True
```

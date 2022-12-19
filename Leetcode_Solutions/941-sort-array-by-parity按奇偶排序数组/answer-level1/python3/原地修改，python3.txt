```
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        start,end=0,len(A)-1
        while start<end:
            if A[start]%2 and not A[end]%2:
                A[start],A[end]=A[end],A[start]
                continue
            elif not A[start]%2:
                start+=1
            elif A[end]%2:
                end-=1
        return A

```

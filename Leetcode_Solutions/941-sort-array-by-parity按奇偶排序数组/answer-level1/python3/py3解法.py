双指针
```
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        m=0
        for i in range(len(A)):
            if A[i]%2==0:
                A[m],A[i]=A[i],A[m]
                m+=1
        return A
```

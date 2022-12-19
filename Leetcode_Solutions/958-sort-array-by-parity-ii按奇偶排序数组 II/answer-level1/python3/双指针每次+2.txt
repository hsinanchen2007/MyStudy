```
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        n = len(A)
        i=0 # even
        j=1 # odd
        while  True:
            while  i<n and (A[i] & 1)==0:
                i+=2
            while j<n+1 and (A[j] & 1)==1:
                j+=2
            if i == n or j == n+1:
                break
            A[i],A[j] = A[j],A[i]
        return A
        
```
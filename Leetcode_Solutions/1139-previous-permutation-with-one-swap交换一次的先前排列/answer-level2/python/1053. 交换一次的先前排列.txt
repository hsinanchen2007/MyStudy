
```
class Solution(object):
    def prevPermOpt1(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        n=len(A)
        for i in range(n-1,0,-1):
            if A[i]>=A[i-1]:
                continue
            
            for j in range(n-1,i-1,-1):
                if A[j]<A[i-1] and A[j]!=A[j-1]:
                    A[i-1],A[j]=A[j],A[i-1]
                    return A
        return A
        
```

```
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        A1=[]
        n = len(A)
        for i in range(0,n):
            x = A[i]**2
            A1.append(x)
        A1.sort()
        return A1
```



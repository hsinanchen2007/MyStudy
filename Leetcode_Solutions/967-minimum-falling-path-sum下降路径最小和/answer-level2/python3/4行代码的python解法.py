```
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        for i in range(1, len(A)):
            for j in range(len(A)):
                A[i][j] += min(A[i-1][max(0,j-1): min(j+2,len(A))])
        return min(A[-1])
```
巧妙的利用min()和max()代替了边界的判断，等价于
```
if j==0:
    A[i][j] += min(A[i-1][j],A[i-1][j+1])
elif j == len(A)-1:
    A[i][j] += min(A[i-1][j],A[i-1][j-1])
else:
    A[i][j] += min(A[i-1][j-1], A[i-1][j],A[i-1][j+1])
```


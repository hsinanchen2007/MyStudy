公式: 
L[1][0] += min(L[0][0], L[0][1])
L[1][1] += min(L[0][0], L[0][1], L[0][2])
L[1][2] += min(L[0][1], L[0][2])

(但是需要考虑边界问题)
L[n][m] += min(L[n-1][m-1], L[n-1][m], L[n-1][m])

```
class Solution(object):
    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        _len = len(A)
        if _len == 0:
            return A[0][0]
        for i in range(1, _len):
            for j in range(0, _len):
                if j == 0:
                    A[i][j] += min(A[i-1][j], A[i-1][j+1])
                elif j == _len - 1:
                    A[i][j] += min(A[i-1][j-1], A[i-1][j])
                else:  
                    A[i][j] += min(A[i-1][j-1], A[i-1][j], A[i-1][j+1])
        return min(A[-1])
```
![screenshot.png](https://pic.leetcode-cn.com/665a83b7553eb13a93badb7384cc9c29bb89b52bc409229ee336062b9363205e-screenshot.png)

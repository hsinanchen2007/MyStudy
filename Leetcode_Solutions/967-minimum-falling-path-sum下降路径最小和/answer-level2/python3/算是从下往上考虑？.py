### 解题思路
和答案思路差不多，只不过考虑的角度是要想让某个位置下降和最小，那么该位置上层的相邻位置应该是最小的那个

### 代码

```python3
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        n = len(A)
        if n == 1:
            return A[0][0]

        for i in range(1, n):
            for j in range(n):
                A[i][j] += min(A[i-1][max(0, j-1)], A[i-1][j], A[i-1][min(n-1, j+1)])
        
        return min(A[n-1])
        

```
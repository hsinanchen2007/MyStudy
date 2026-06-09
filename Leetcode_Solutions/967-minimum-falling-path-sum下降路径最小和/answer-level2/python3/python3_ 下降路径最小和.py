```python
def minFallingPathSum(A):
    """
        1. dp问题: dp[i][j] += min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])
    """
    if not A:
        return 0
    m, n = len(A), len(A[0])
    for i in range(1, m):
        for j in range(n):
            _min = A[i-1][j]
            if j - 1 >= 0:
                _min = min(_min, A[i-1][j-1])
            if j + 1 < n:
                _min = min(_min, A[i-1][j+1])
            A[i][j] += _min
    
    return min(A[-1])

print(minFallingPathSum([[1,2,3],[4,5,6],[7,8,9]]))
```
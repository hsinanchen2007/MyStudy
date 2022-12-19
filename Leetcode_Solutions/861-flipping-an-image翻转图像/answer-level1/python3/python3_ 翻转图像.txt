```python
def flipAndInvertImage(A):
    m, n = len(A), len(A[0])
    for i in range(m):
        j, k = 0, n - 1
        # 行翻转
        while j < k:
            A[i][j], A[i][k] = A[i][k], A[i][j]
            j += 1
            k -= 1
    
    # 0, 1互换
    for i in range(m):
        for j in range(n):
            A[i][j] = 1 if A[i][j] == 0 else 0
            
    return A

print(flipAndInvertImage([[1,1,0],[1,0,1],[0,0,0]]))
```
```python
def transpose(A):
    m, n = len(A), len(A[0])
    r = [[0 for i in range(m)] for j in range(n)]
    # 不推荐使用临时变量 + 在矩阵A上直接修改. 这样代码不太好理解.
    for i in range(n):
        for j in range(m):
            r[i][j] = A[j][i]

    return r

def transpose1(A):
    return list(zip(*A))

print(transpose([[1,2,3],[4,5,6],[7,8,9]]))
print(transpose1([[1,2,3],[4,5,6],[7,8,9]]))
```
### 解题思路
这里矩阵转置必然要生成一个新的矩阵，考虑 m*n 转置后变为 n*m

已知是矩阵，而不仅仅是二维数组，必有所有 A[i] 的长度都相同

B[i][j] = A[j][i]

第一次提交报错，是因为 直接在 A 上原地改，但当 A 不是对称矩阵时，就会导致下标出错。


### 代码

```python3
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        # 已知是矩阵，而不仅仅是二维数组，必有所有 A[i] 的长度都相同
        m, n = len(A), len(A[0])
        B = []
        for i in range(n):
            B.append([])
            for j in range(m):
                B[i].append(A[j][i])
        return B

```
### 第一次提交的错误代码
``` python3
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        # 已知是矩阵，而不仅仅是二维数组，必有所有 A[i] 的长度都相同
        for i in range(len(A)):
            for j in range(i+1, len(A[0])):
                A[i][j], A[j][i] = A[j][i], A[i][j]
        return A
```
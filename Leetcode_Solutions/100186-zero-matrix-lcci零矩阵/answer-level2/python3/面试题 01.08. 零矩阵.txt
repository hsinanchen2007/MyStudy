### 解题思路

动态类型语言有优势。

### 代码

```python []
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        for i, j in itertools.product(range(m), range(n)):
            if matrix[i][j] == 0:
                for k in range(m):
                    if matrix[k][j] != 0:
                        matrix[k][j] = None
                for k in range(n):
                    if matrix[i][k] != 0:
                        matrix[i][k] = None
        for i, j in itertools.product(range(m), range(n)):
            if matrix[i][j] is None:
                matrix[i][j] = 0
```
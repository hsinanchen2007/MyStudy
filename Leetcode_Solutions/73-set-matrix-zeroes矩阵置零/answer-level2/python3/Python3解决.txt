### 解题思路
暴力法模拟

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        res = set()
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    res.add((i, j))
        for k in range(len(res)):
            i, j = res.pop()
            for m in range(len(matrix)):
                matrix[m][j] = 0
            for n in range(len(matrix[0])):
                matrix[i][n] = 0
        # print(matrix)
        return matrix
```
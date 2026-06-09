### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    for n in range(len(matrix[i])):
                        if matrix[i][n] != 0:
                            matrix[i][n] = None
                    for m in range(len(matrix)):
                        if matrix[m][j] != 0:
                            matrix[m][j] = None
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == None:
                    matrix[i][j] = 0
```
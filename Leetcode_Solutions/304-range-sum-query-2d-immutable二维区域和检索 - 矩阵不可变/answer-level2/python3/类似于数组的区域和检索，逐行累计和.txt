类似于一维(数组)的区域和检索，我们可以在dp矩阵中的每一行记录matrix的每一行对应的累计和。

主要对dp矩阵预处理时多加一行一列的全0，因为要包含选定的矩阵区域。

语言描述起来比较麻烦，还是直接看代码把。

```python []
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        if matrix == None or len(matrix) == 0:
            self.dp = None
        else:
            row = len(matrix)
            col = len(matrix[0][:])
            
            self.dp = [[0 for j in range(col+1)] for i in range(row+1)]
            for i in range(1, row+1):
                for j in range(1, col+1):
                    if j == 1:
                        self.dp[i][j] = matrix[i-1][j-1]
                    else:
                        self.dp[i][j] = self.dp[i][j-1] + matrix[i-1][j-1]
                

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row1, col1, row2, col2 = row1+1, col1+1, row2+1, col2+1
        res = 0
        if self.dp != None:
            for i in range(row1, row2+1):
                res += self.dp[i][col2] - self.dp[i][col1-1]
            
        return res
```

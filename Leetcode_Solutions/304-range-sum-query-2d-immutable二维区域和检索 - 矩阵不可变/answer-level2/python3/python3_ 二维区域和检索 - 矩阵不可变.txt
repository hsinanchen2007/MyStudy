```python
class NumMatrix:

    def __init__(self, matrix):
        """
            1. dp问题, 先计算到i,j位置的和.
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j]
                [i-1, j-1]重复计算了, 所以需要减去.
            2. 在计算range时候, 以[2,1,4,3]为例:
            dp[4][3] - (dp[4][1-1](第一列) + dp[2-1][3](前两行到第四列为止) - dp[2-1][1-1](重复计算部分))
        """
        # 处理空的情况
        if not matrix:
            self.dp = [[]]
            return
        m, n = len(matrix), len(matrix[0])
        # 初始化dp
        self.dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                self.dp[i][j] = matrix[i][j]
                # 计算[i][j]部分的和
                if i - 1 >= 0 and j - 1 >= 0:
                    self.dp[i][j] += self.dp[i-1][j] + self.dp[i][j-1] - self.dp[i-1][j-1]
                elif i - 1 >= 0:
                    self.dp[i][j] += self.dp[i-1][j]
                elif j - 1 >= 0:
                    self.dp[i][j] += self.dp[i][j-1]
                

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        v = 0
        if col1 - 1 >= 0: v += self.dp[row2][col1-1]
        if row1 - 1 >= 0: v += self.dp[row1-1][col2]
        if col1 - 1 >= 0 and row1 - 1 >= 0: v -= self.dp[row1-1][col1-1]
        return self.dp[row2][col2] - v
```
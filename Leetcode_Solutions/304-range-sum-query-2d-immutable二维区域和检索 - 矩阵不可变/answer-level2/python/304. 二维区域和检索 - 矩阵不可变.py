### 解题思路
**动态规划**，二维数组缓存矩阵面积

### 代码

```python
class NumMatrix(object):

    def __init__(self, matrix):
        self.matrix = matrix
        if len(self.matrix) == 0 or len(self.matrix[0]) == 0:
            return 
        self.r = len(matrix)
        self.c = len(matrix[0])
        #dp[i][j]表示以(0,0)为左上角 (i,j)为右下角的矩阵的面积
        self.dp = [[0] * self.c for _ in range(self.r)]
        self.dp[0][0] = matrix[0][0]
        #首先确定0行0列的矩阵面积
        for j in range(1,self.c):
            self.dp[0][j] = matrix[0][j] + self.dp[0][j-1]
        for i in range(1,self.r):
            self.dp[i][0] = matrix[i][0] + self.dp[i-1][0]
        for i in range(1,self.r):
            for j in range(1,self.c):
                self.dp[i][j] = self.dp[i-1][j] + self.dp[i][j-1] - self.dp[i-1][j-1] + self.matrix[i][j]
    
        

    def sumRegion(self, row1, col1, row2, col2):
        if row1 == 0 and col1 == 0:
            return self.dp[row2][col2]
        else:
            if row1 == 0:
                return self.dp[row2][col2] - self.dp[row2][col1-1]
            if col1 == 0:
                return self.dp[row2][col2] - self.dp[row1-1][col2]
        return self.dp[row2][col2] - self.dp[row1-1][col2] - self.dp[row2][col1-1] + self.dp[row1-1][col1-1]
        

```
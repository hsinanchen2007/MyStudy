### 解题思路
动态方程：
1. 构建阶段，保证每一个取值为从左顶点到（i，j）所有元素的和
$$
dp[i][j] = matrix[i][j] + dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]
$$

2. 求和阶段（ 蓝圈总值=D-C-B+A  减去B与C时，A区域重复减去了两次，所以最后再补加一次）

$$
sum = dp[r_2][c_2]- dp[r_2][c_1-1]-dp[r_2-1][c_2]+dp[r_1-1][c_1-1]
$$
![XX.png](https://pic.leetcode-cn.com/2b7930de9b25c6f6c47d3030aec50265ddf046c5605dbfed54c5ef9abce40e5e-XX.png)



3. 初始化
    为了保留原数组，并且在计算时的便捷，定义了dp数组：只是在matrix外层增加了半圈0



### 代码

```python3
class NumMatrix:
    def __init__(self, matrix):
        if (not matrix) or (not matrix[0]):return
        m = len(matrix)
        n = len(matrix[0])
        self.dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                # 构建阶段
                self.dp[i][j] = matrix[i-1][j-1]+self.dp[i-1][j]+self.dp[i][j-1]-self.dp[i-1][j-1]


    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        #  求和阶段
        return  self.dp[row2+1][col2+1] - self.dp[row2+1][col1] - self.dp[row1][col2+1] + self.dp[row1][col1]

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
```
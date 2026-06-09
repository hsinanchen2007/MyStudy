### 解题思路
方程：dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j]

dp[i][j]表示以[i][j]位置作为矩形的右下角，[0][0]位置作为矩形的左上角，

这两个位置所确定的唯一矩形内元素之和

调用sumRegion函数计算时，使用dp提供的缓存表辅助计算

本质上就是大|小矩形之间的加加减减，但是需要注意边界情况

![捕获.PNG](https://pic.leetcode-cn.com/9b48bbadfdf9a534ee11e442decb443cf6726f1fbdb4cff01cc41cd1b20a6201-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```python
class NumMatrix:
    # 动态规划
    # dp[i][j]表示以[i][j]位置作为矩形的右下角，二维矩阵左上角作为矩形的左上角形成的矩形范围内元素和
    # dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j]
    def __init__(self, matrix: List[List[int]]):
        # 二维矩阵的行列数
        m = len(matrix)
        # 二维矩阵为空
        if m == 0:
            return 
        n = len(matrix[0])
        self.dp = [[0 for _ in range(n)] for _ in range(m)]
        self.dp[0][0] = matrix[0][0]
        # 初始化第一列和第一行
        for i in range(1,m):
            self.dp[i][0] = self.dp[i-1][0] + matrix[i][0]
        for j in range(1,n):
            self.dp[0][j] = self.dp[0][j-1] + matrix[0][j]
        # 从[1][1]开始计算
        for i in range(1,m):
            for j in range(1,n):
                self.dp[i][j] = self.dp[i-1][j] + self.dp[i][j-1] - self.dp[i-1][j-1] + matrix[i][j]
        # print(self.dp)

    # 分为4种情况讨论    
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sum_val = 0
        if row1 == 0 and col1 == 0:
            sum_val = self.dp[row2][col2]
        elif row1 == 0:
            sum_val = self.dp[row2][col2] - self.dp[row2][col1-1]
        elif col1 == 0:
            sum_val = self.dp[row2][col2] - self.dp[row1-1][col2]
        else:
            sum_val = self.dp[row2][col2] - self.dp[row2][col1-1] - self.dp[row1-1][col2] + self.dp[row1-1][col1-1]
        return sum_val
            

        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
```
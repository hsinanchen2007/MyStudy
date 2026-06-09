### 解题思路
详见注释
需要注意的点
1. python的二维列表的初始化操作不能写成dp = [[0]*m]*n 似乎和python的深拷贝浅拷贝有关
2. 如果接受的参数为空，则不存在matrix[0]，所以获取不到列数，只能根据行数为0返回0
![捕获.PNG](https://pic.leetcode-cn.com/17b5307a4f5453c6adeb8bdfac3b1f2a230651fa2a91f0782ba94dd9b8e9327d-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```python3
class Solution:
    # 知道边长可以知道面积
    # 以[i][j]位置的数作为正方形右下角
    # dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        max_val = 0
        m = len(matrix)
        if m == 0:
            return 0;
        n = len(matrix[0])
        dp = [[0]*n for _ in range(m)] 
        # 特殊情况判断;初始化第一行和第一列
        for i in range(m):
            dp[i][0] = int(matrix[i][0])
            if matrix[i][0] == '1':
                max_val = 1
        for j in range(1,n):
            dp[0][j] = int(matrix[0][j])
            if matrix[0][j] == '1':
                max_val = 1

        for i in range(1,m):
            for j in range(1,n):
                if matrix[i][j] == '1':
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1
                    if dp[i][j] > max_val:
                        max_val = dp[i][j]
        return max_val**2

```
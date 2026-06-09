### 解题思路
转移方程dp[i][j]=min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1
也就是说当前正方形的变长是由左上角，上方，左方三个地方的最小正值确定
### 代码

```
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        row,col=len(matrix),len(matrix[0])
        dp=[[0]*(col+1) for _ in range(row+1)]
        for i in range(1,row+1):
            for j in range(1,col+1):
                if matrix[i-1][j-1]=="1":
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
        return max(max(i) for i in dp)**2

        


       
```
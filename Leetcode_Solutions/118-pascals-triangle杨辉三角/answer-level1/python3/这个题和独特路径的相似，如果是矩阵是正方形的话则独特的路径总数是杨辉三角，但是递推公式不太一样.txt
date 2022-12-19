### 解题思路
这个题和独特路径的相似，如果是矩阵是正方形的话则独特的路径总数是杨辉三角
dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
独特路径
dp[i][j]=dp[i][j-1]+dp[i-1][j]

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        dp=[[0]*n for n in range(1,numRows+1)] 
        for i in range(numRows):
            dp[i][0]=dp[i][-1]=1
        for i in range(0,numRows):
            for j in range(i+1):
                if(dp[i][j]==0):
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
        return dp

```
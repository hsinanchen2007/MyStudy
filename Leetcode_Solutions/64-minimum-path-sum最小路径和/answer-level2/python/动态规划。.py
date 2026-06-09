### 解题思路
此处撰写解题思路
发现好多类似的题，都可以先考虑。
1、要知道grid[i][j]的值，需要知道前一步grid[i-1][j]或grid[i][j-1]的值
2、构造一个中间矩阵dp，存入各种到当前值得最小路径的值得和，如要到grid[0][1],那只有一种可能即从grid[0][0]，向右一步，那dp[0][1] = dp[0][0] + grid[0][1] =1+3=4. 同理，到grid[1][1]，则有两条路，即分别从grid[0][1],grid[1][0]而来，取两者的最小值。
3、基于第2步的分析，转移方程为dp[i][j] = min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]).
4、dp的边界条件（1），矩阵为空返回0，(2)最上面一行的值之能由左侧的值叠加而来，(3)最左侧一列的值之能由上面的值叠加而来。
### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                #定义起点
                if i == 0 and j == 0:
                    dp[i][j] = grid[0][0]
                
                #最顶部的节点，其来源只能有一种，就是从左边向右走来
                elif i == 0 and j != 0:
                    dp[i][j] = dp[i][j-1] + grid[i][j]

                #最左边的节点，其来源只能有一种，就是从上面向下走来
                elif j == 0 and i != 0:
                    dp[i][j] = dp[i-1][j] + grid[i][j]

                #中间的节点，可以是从上或从左侧走来，然后取小值
                else:
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j]
        return dp[m-1][n-1]
```
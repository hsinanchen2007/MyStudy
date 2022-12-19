### 解题思路

非优化：
1.定义状态：即定义数组元素的含义，grid[i][j]当前位置的最小数值总和

2.建立状态转移方程:grid[i][j] = min(grid[i-1][j],grid[i][j-1])+num,num为当前值

3.设定初始值：grid[0][j] 为前j列的累加值，grid[i][j]为前i行的累加值

4.压缩数据：即优化数组，减小复杂度，本题可以优化，降低数组维度，为一维

5.选择结果，因为是累加，所以选择数组最后一个数值，即grid[-1][-1]


优化：
1.定义状态：即定义数组元素的含义,dp[i]表示当前位置的最小数值综合

2.建立状态转移方程:dp[i] = min(dp[i-1],dp[i])+grid[i,j]

3.设定初始值:这一步是关键,我的方法是初始化第一行为累加，以该题的例子为例，即dp = [1,4,5]，然后需在每次换行中添加一个判断条件，用于生成第一列的累加值，动态比较最小值。

4.选择结果，即dp[-1]


过程分析：
dp = [1,4,5]
       ||
     [2,7,6]
       ||
     [6,8,7]

得到：dp[-1]即为路径数字总和最小


### 代码

```python
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        # 非优化动态规划，时间复杂度O(m*n)，空间复杂度O(n*m)
        m = len(grid)
        n = len(grid[0])
        for i in range(1,n):
            grid[0][i] += grid[0][i-1]
        for j in range(1,m):
            grid[j][0] += grid[j-1][0]
        for i in range(1,m):
            for j in range(1,n):
                grid[i][j] = min(grid[i-1][j],grid[i][j-1]) + grid[i][j]
        return grid[-1][-1]
        

        # 优化算法,即求每次到达位置的最优解
        # 定义状态：即定义数组元素的含义,dp[i]表示当前位置的最小数值综合
        # 建立状态转移方程:dp[i] = min(dp[i-1],dp[i])+grid[i,j]
        # 设定初始值:这一步是关键
        # 选择结果，即dp[-1]
        m = len(grid)
        n = len(grid[0])
        dp = [0]*n
        dp[0] = grid[0][0]
        for k in range(1,n):
            dp[k] = dp[k-1] + grid[0][k] 
        for i in range(1,m):
            for j in range(0,n):
                if j == 0 : dp[j] += grid[i][j]
                else:
                    dp[j] = min(dp[j-1],dp[j])+grid[i][j]
        return dp[-1]
```
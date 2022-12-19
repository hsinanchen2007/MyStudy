### 解题思路
举了例子：
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

dp变化过程：

dp = [1,0,0,0]
        ||
     [1,1,1,0]
        ||
     [1,0,1,0]
        ||
     [1,1,2,0]

所以最终dp = [1,1,2,0]
总条数：dp[-2],即 2

核心代码：dp[j] = 0 if obstacleGrid[i][j] else dp[j]+dp[j-1]

判断当前位置是否为障碍物，如果是的话，将该点赋值为0,不是的话,动态更新当前位置的最新路径条数，并覆盖。
dp中最后一个值不会对原本矩阵产生影响。

### 代码

```python
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        # 定义状态：即数据元素的含义：dp表示当前位置的路径条数
        # 建立状态转移方程：dp[i] = dp[i]+dp[i-1]
        # 设定初始值：增加初始值1，即dp = [1] + [0]*n
        # 状态压缩：即优化数组空间,将二维数组压缩到一维数组,逐行计算当前最新路径条数，并覆盖上一行对应的路径条数
        # 选取dp[-2]表示到达finish位置路径总条数,因为一开始新增加的1,因此最终值要往前推一个
        
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [1] + [0]*n
        for i in range(0,m):
            for j in range(0,n):
                dp[j] = 0 if obstacleGrid[i][j] else dp[j]+dp[j-1]
        return dp[-2]
                

```
#### 说明：
 - 动态规划思想，和 [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) 基本一致
 - 关于解法的图解， [官方题解的图解](https://leetcode-cn.com/problems/unique-paths-ii/solution/bu-tong-lu-jing-ii-by-leetcode/) 很棒，建议参考
 - 状态转移方程为 $dp[i][j] = dp[i - 1][j] + dp[i][j - 1], 其中i > 1, j > 1$
 - 将障碍物点定义 $0$ ，即直接设置障碍物点的可到达路径数为0，而不使用状态转移方程求解
#### 效率：
> Runtime: 48 ms, faster than 96.80% of Python3 online submissions for Unique Paths II.
> Memory Usage: 14 MB, less than 8.89% of Python3 online submissions for Unique Paths II.
#### 复杂度分析：
 - 时间复杂度：$O(m*n)$
   两次遍历二维数组``obstacleGrid``
 - 空间复杂度：$O(1)$
 创建了``常数级别``的变量；原地修改二维数组``obstacleGrid``内的值
#### 代码：
```Python
from typing import List


class Solution:

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

        # 定义障碍物点，可通行点
        obstacle, walkable = 0, 1
        # 定义路径范围的高度，长度
        height, width = len(obstacleGrid), len(obstacleGrid[0])

        # 将障碍物定义为1改成定义为obstacle, 其余为walkable
        for h in range(height):
            for w in range(width):
                obstacleGrid[h][w] = obstacle if obstacleGrid[h][w] == 1 else walkable

        # 如果起点或者终点为障碍物点，则无法达到
        if obstacleGrid[0][0] is obstacle or obstacleGrid[-1][-1] is obstacle:
            return 0

        # 处理第一行，转化为路径值
        for w in range(1, width):
            # 如果前一个点为障碍物点，那么该点无法到达，视为障碍物点
            if obstacleGrid[0][w - 1] is obstacle:
                obstacleGrid[0][w] = obstacle

        # 处理第一列，转化为路径
        for h in range(1, height):
            # 如果前一个点为障碍物点，那么该点无法到达，视为障碍物点
            if obstacleGrid[h - 1][0] is obstacle:
                obstacleGrid[h][0] = obstacle

        for h in range(1, height):
            for w in range(1, width):

                # 根据当前点值进行判断
                if obstacleGrid[h][w] is obstacle:
                    # 如果当前点为障碍物，则到达该点有零条路径
                    continue
                else:
                    # 否则，到达当前点的路径值为dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                    obstacleGrid[h][w] = obstacleGrid[h - 1][w] + obstacleGrid[h][w - 1]

        return obstacleGrid[-1][-1]
```
动态规划，但需要考虑的情况相比于上一道题比较多。
    1. 首先若起始点`obstacleGrid[0][0]`为1，则无论如何无法到达终点，返回0。
    2. 其次，初始化dp数组时，需要考虑当第一行/第一列的某个位置为1的情况：
        若第一行/第一列的某个位置为1，则该位置之后的位置均应初始化为0。
        因为对于第一行/第一列来说，位置`i`只能由位置`i-1`向右/向下移动得到。
        因此，此时将dp数组初始化为0，之后遍历obstacleGrid第一行/第一列，若位置i为0，则将dp的对应位置置为1。否则跳出循环，不更改后面的值。
        当只有一行或一列时，用于我们已经初始化了矩阵第一行和第一列的情况，可以直接返回`dp[-1][-1]`。
    3. 最后，当数组不止一行或一列时，利用状态转移方程完成dp数组的更新。
```
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if not obstacleGrid or obstacleGrid[0][0] == 1:
            return 0

        # 构建m行n列的dp矩阵
        # dp[i][j]代表从[0][0]到[i][j]的路线数，初始化为全0
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        # 遍历obstacleGrid的第一行和第一列，若在某个位置出现障碍物"1"，则将该为之后的dp元素置为0。
        for i in range(m):
            if obstacleGrid[i][0] == 0:
                dp[i][0] = 1
            else:
                break
        for j in range(n):
            if obstacleGrid[0][j] == 0:
                dp[0][j] = 1
            else:
                break
        # 当只有一行或一列时，用于我们已经初始化了矩阵第一行和第一列的情况，可以直接返回dp[-1][-1]
        if m == 1 or n == 1:
            return dp[-1][-1]
        
        # 矩阵多行多列的情况：
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
                
                
        return dp[-1][-1]
```

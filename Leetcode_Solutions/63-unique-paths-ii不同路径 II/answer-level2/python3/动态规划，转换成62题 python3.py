# 题解
62.不同路径[CSDN](https://blog.csdn.net/zhushaojiecumt/article/details/102938160)或[LeetCode](https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-kong-jian-you-hua-python3-by-zhu_/)
和62不同的是，本题边界上的路径数受障碍物的影响且网格处存在障碍物，则到达此处的路径数为0。
因此，只需在边界路径数上和更新路径时做些改变就可满足本题要求。
## 动态规划

 1. 特判:
 	* 若$obstacleGrid$为空，返回$0$
 	* 若左上角或者右下角任意一个位置存在障碍物则返回$0$，即$obstacleGrid[0][0]==1 or obstacleGrid[-1][-1]==1$
 2. 初始化数组行数$m$和列数$n$。初始化动态数组$dp$，$dp$为$m*n$维数组，所有位置初始化为$0$，$dp[0][0]=1$表示起点的路径总数（因为特判去除了起点不可达的情况，所以一定可达）
 3. 初始化第一行的边界路径，遍历区间$[1,n)$：若满足条件$obstacleGrid[0][i]!=1$，表示当前位置没有障碍物，$dp[0][i]$等于上一位置的路径数$dp[0][i-1]$。若不满足，则保持为$0$
 4. 初始化第一列的边界路径，遍历区间$[1,m)$：若满足条件$obstacleGrid[i][0]!=1$，表示当前位置没有障碍物，$dp[j][0]$等于上一位置的路径数$dp[j-1][0]$。若不满足，则保持为$0$
 5. 和62题一样，遍历每一行，遍历区间$[1,m)$：
 	* 遍历每一列，遍历区间$[1,n)$：
 		+ 若网格$(x,y)$处没有障碍物，即$obstacleGrid[x][y]!=1$，则网格$(x,y)$处的路径数等于网格$(x-1,y)$和网格$(x,y-1)$处的路径之和，即$dp[x][y]=dp[x-1][y]+dp[x][y-1]$。
 6. 返回右下角的路径数，$dp[-1][-1]$。

### 复杂度分析
 - 时间复杂度：$O(M*N)$
 - 空间复杂度：$O(M*N)$，借助$dp$数组保存结果

### Python

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if(not obstacleGrid):
            return 0
        if(obstacleGrid[0][0]==1 or obstacleGrid[-1][-1]==1):
            return 0
        m=len(obstacleGrid)
        n=len(obstacleGrid[0])
        dp=[[0]*n for _ in range(m)]
        dp[0][0]=1
        for i in range(1,n):
            if(obstacleGrid[0][i]!=1):
                dp[0][i]=dp[0][i-1]
        for j in range(1,m):
            if(obstacleGrid[j][0]!=1):
                dp[j][0]=dp[j-1][0]
        for x in range(1,m):
            for y in range(1,n):
                if(obstacleGrid[x][y]!=1):
                    dp[x][y]=dp[x-1][y]+dp[x][y-1]
        return dp[-1][-1]
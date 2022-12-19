### 解题思路
1. 用动态规划，对所有点，求它到达终点的路径中的下一步，0-向右，1-向左，2-无法到达
2. 从起点`[0,0]`开始，沿着标记一直走到终点`[n-1,m-1]`，将沿途经过的点加入`ans`
3. 为了节省空间，动态规划的可以直接保存在obstacleGrid，这样就不需要再额外申请一个动态规划数组

### 复杂度
1. 时间：`O(m*n)`
2. 空间：`O(1)`

### 代码

```python3
class Solution:
    def pathWithObstacles(self, obstacleGrid: List[List[int]]) -> List[List[int]]:
        if len(obstacleGrid) == 0 or len(obstacleGrid[0]) == 0: return []
        n, m = len(obstacleGrid), len(obstacleGrid[0])
        # 对所有点，求它到达终点的路径中的下一步，0-向右，1-向左，2-无法到达
        # 用动态规划求解，自下而上，自右而左
        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                if obstacleGrid[i][j] == 1: obstacleGrid[i][j] = 2
                elif i == n-1 and j == m-1: obstacleGrid[i][j] = 1
                elif i == n-1: 
                    obstacleGrid[i][j] = (obstacleGrid[i][j+1] == 2) and 2 or 0
                elif j == m-1:
                    obstacleGrid[i][j] = (obstacleGrid[i+1][j] == 2) and 2 or 1
                else:
                    obstacleGrid[i][j] = (obstacleGrid[i][j+1] == 2) and ((obstacleGrid[i+1][j] == 2) and 2 or 1) or 0
        # 从起点开始，沿着标记一直走到终点
        ans, i, j = [], 0, 0
        while i < n and j < m and obstacleGrid[i][j] != 2:
            ans.append([i, j])
            if obstacleGrid[i][j] == 0: j += 1
            else: i += 1
        return ans
```
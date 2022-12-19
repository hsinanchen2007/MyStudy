### 解题思路
全在注释中  
 path_trace【i】【j】,到i j 位置上 有多少种不同的路径
### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid or obstacleGrid[0][0] == 1 or obstacleGrid[-1][-1] == 1:
            return 0
        # 到i j 位置上 有多少种不同的路径  # 只能向右 或者向下
        col = len(obstacleGrid[0])
        row = len(obstacleGrid)
        path_trace = [[0 for _ in range(col)] for _ in range(row)]
        # path_trace[i][j]
        path_trace[0][0] = 1

        # 到达i j的位置
        for i in range(1, row):
            if obstacleGrid[i][0] == 1 or path_trace[i - 1][0] == 0:
                # 那么他的后面都是 0
                path_trace[i][0] = 0
            else:
                path_trace[i][0] = 1

        for j in range(1, col):
            if obstacleGrid[0][j] == 1 or path_trace[0][j - 1] == 0:
                path_trace[0][j] = 0
            else:
                path_trace[0][j] = 1
        for i in range(1, row):
            for j in range(1, col):
                # 如果当前是 0 表示可达
                if obstacleGrid[i][j] == 0:
                    path_trace[i][j] = path_trace[i - 1][j]+ path_trace[i][j - 1]
                else:
                    # 如果当前是 1
                    path_trace[i][j] = 0
        return path_trace[-1][-1]

```
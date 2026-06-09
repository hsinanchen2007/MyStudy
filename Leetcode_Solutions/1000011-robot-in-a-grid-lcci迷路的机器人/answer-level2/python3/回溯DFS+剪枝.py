### 解题思路


### 代码

```python3
class Solution:
    def pathWithObstacles(self, obstacleGrid: List[List[int]]) -> List[List[int]]:
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        res = []
        if row < 2 and col < 2:
            if obstacleGrid[0][0] == 1:
                return []
            else:
                res.append([0, 0])
                return res
        if obstacleGrid[-1][-1] == 1:
            return []

        def dfs(x: int, y: int, path: List[int]):
            if x == row - 1 and y == col - 1:
                res.append(path)
                return True

            if x >= row or y >= col:
                return
            if obstacleGrid[x][y] == 0:
                obstacleGrid[x][y] = 1

                if dfs(x + 1, y, path + [[x + 1, y]]):
                    return True

                if dfs(x, y + 1, path + [[x, y + 1]]):
                    return True
               # obstacleGrid[x][y] = 0
        dfs(0, 0, [[0, 0]])
        return res[0] if res else res
```
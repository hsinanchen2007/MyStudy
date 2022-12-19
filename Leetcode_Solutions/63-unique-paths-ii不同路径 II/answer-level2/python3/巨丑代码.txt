### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid)-1
        m = len(obstacleGrid[0])-1
        res = {}
        if obstacleGrid[n][m] == 1 or obstacleGrid[0][0] == 1:
            return 0
        for m1 in range(m, -1, -1):
            if obstacleGrid[n][m1] == 1:
                res[n, m1] = 0
                for m11 in range(m1, -1, -1):
                    res[n, m11] = 0
                break
            else:
                res[n, m1] = 1
        for n1 in range(n, -1, -1):
            if obstacleGrid[n1][m] == 1:
                res[n1, m] = 0
                for n11 in range(n1, -1, -1):
                    res[n11, m] = 0
                break
            else:
                res[n1, m] = 1
        for j in range(n-1, -1, -1):
            for i in range(m-1, -1, -1):
                if obstacleGrid[j][i] == 1:
                    res[j, i] = 0
                else:
                    res[j, i] = res[j, i+1] + res[j+1, i]
        return res[0,0]

```
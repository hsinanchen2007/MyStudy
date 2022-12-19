大致思路和官方一样。这里用了一个小技巧可以直接在原数组上修改。就是把每个数从2开始算。
2就是1，4就是2，8就是4
所以把最后答案整数除法除以2就行了
如果到达不了则最后的数为1，除出来是0

```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        mflag=0
        nflag=0
        for i in range(m):
            if not obstacleGrid[i][0] == 1 and not mflag:
                obstacleGrid[i][0] = 2
            else:
                mflag=1
                obstacleGrid[i][0] = 1
        for i in range(n):
            if not obstacleGrid[0][i] == 1 and not nflag:
                obstacleGrid[0][i] = 2
            else:
                nflag=1
                obstacleGrid[0][i] = 1
        for i in range(1, m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 1:
                    continue
                elif obstacleGrid[i][j - 1] == 1 and obstacleGrid[i - 1][j] == 1:
                    obstacleGrid[i][j] = 1
                    continue
                elif obstacleGrid[i][j - 1] == 1 and not obstacleGrid[i - 1][j] == 1:
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j]
                    continue
                elif not obstacleGrid[i][j - 1] == 1 and obstacleGrid[i - 1][j] == 1:
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1]
                    continue
                elif not obstacleGrid[i][j - 1] == 1 and not obstacleGrid[i - 1][j] == 1:
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
                    continue
        return obstacleGrid[-1][-1] // 2
        
```

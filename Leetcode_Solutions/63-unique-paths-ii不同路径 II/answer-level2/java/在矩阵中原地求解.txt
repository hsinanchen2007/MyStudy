思路：由于矩阵中只会存在0和1，所以我们可以用负数来表示走到当前节点的不同路径数。当某个节点的左边节点或上边节点为1时，说明有障碍物，当前节点的路径数累计则可以不考虑障碍物。最后返回前取grid的最后一个结点，如果结点为1，则不可能走到这里，其他情况则应该取负再返回。
```
public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        obstacleGrid[0][0] = -1;
        for (int i = 0; i < obstacleGrid.length; i++) {
            for (int j = 0, end = obstacleGrid[0].length; j < end; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }

                if (i > 0 && obstacleGrid[i - 1][j] != 1) {
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                }
                if (j > 0 && obstacleGrid[i][j - 1] != 1) {
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                }
            }
        }

        int x = obstacleGrid[obstacleGrid.length - 1][obstacleGrid[0].length - 1];
        return x == 1 ? 0 : -x;
    }
```

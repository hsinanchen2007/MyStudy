```
public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
            return 0;
        int row = obstacleGrid.length;
        int col = obstacleGrid[0].length;
        int [] memo = new int[col];
        Arrays.fill(memo,0);
        for (int i = 0; i < col; i++) {
            if(obstacleGrid[0][i] == 1)
                break;
            memo[i] = 1;
        }
        for (int i = 1; i < row; i++) {
            if (obstacleGrid[i][0] == 1)
                memo[0] = 0;
            for (int j = 1; j < col; j++) {
                if(obstacleGrid[i][j] == 1)
                    memo[j] = 0;
                else
                    memo[j] += memo[j-1];
            }
        }
        return memo[col-1];
    }
```
注：代码编写借鉴了题目62同一方法的题解

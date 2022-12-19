```
public class UniquePaths_2 {

    /**
     * 在UniquePaths的基础上进行更改
     */
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {

        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        //终点为障碍，无论如何都到达不了，0
        if (obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        //dp数组行列数在obstacleGrid基础上增加一行/列，变成（m+1）*（n+1）
        //多出的行列填充为0，
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            dp[i][n] = 0;
        }
        for (int i = 0; i < n + 1; i++) {
            dp[m][i] = 0;
        }
        //为了让（m*n）元素都可以进入下面的循环
        //在该设置一个1，也可以设置在dp[m][n-1]=1，目的是使m与n都符合循环操作，
        dp[m - 1][n] = 1;

        //补充其它位置的元素
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                //如果某个位置的值为1，则表示障碍，无论右/下位置有多少路径，他都无法到达，即设为0
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    //其余位置正常
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
}
```

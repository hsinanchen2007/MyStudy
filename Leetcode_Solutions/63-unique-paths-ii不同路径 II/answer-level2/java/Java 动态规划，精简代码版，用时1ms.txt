*我的提交执行用时1ms已经战胜 99.67 % 的 java 提交记录*

**动态规划法，判断条件中（条件顺序不能换）**
 - 若数组值为1，则将其值改为0，意味着到达该点的路径数为0
 - 若数组的横纵坐标都大于0，则运用状态转移方程obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
 - 若数组的横坐标为0，则将值与左边的值保持一致
 - 若数组的纵坐标为0，则将值与上边的值保持一致
最终返回obstacleGrid[m-1][n-1];

```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                } else if (i != 0 && j != 0){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                } else if (i == 0 && j == 0){
                    obstacleGrid[i][j] = 1;
                } else if (i == 0 ){
                    obstacleGrid[i][j] =  obstacleGrid[i][j-1];
                } else {
                    obstacleGrid[i][j] =  obstacleGrid[i-1][j];
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
}
```

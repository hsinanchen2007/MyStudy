### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid == null || obstacleGrid.length == 0 || obstacleGrid[0].length == 0){
            return 0;
        }
        int n = obstacleGrid.length; //行
        int m = obstacleGrid[0].length; //列
        int[][] path = new int[n][m];

        for(int i = 0; i < n; i++){
            if(obstacleGrid[i][0] != 1){
                path[i][0] = 1;
            }
            else{
                break;
            }
        }

        for(int i = 0; i < m; i++){
            if(obstacleGrid[0][i] != 1){
                path[0][i] = 1;
            }
            else{
                break;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(obstacleGrid[i][j] != 1){
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
                }
                else{
                    path[i][j] = 0;
                }
            }
        }
        return path[n - 1][m - 1];
    }
}
```
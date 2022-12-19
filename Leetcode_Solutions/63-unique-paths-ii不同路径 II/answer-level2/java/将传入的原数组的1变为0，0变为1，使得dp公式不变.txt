### 解题思路
公式： dp[i][j] = dp[i-1][j] + dp[i][j-1]
1. 将传入的原数组的1变为0，0变为1；
2. 第一行和第一列中，第一个障碍之后的格子都变为0（不可达）
3. dp[i][j] = dp[i-1][j] + dp[i][j-1]
### 代码
```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        if(obstacleGrid[0][0]==1)
            return 0;
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==0)
                    obstacleGrid[i][j] = 1;
                else
                    obstacleGrid[i][j] = 0;
            }

        //若第一行中有障碍物，即该格子为0，则后面的全修改为0（不可达）
        for(int j=0; j<n; j++){
            if(obstacleGrid[0][j]==0){
                for(int k=j+1; k<n; k++){
                    obstacleGrid[0][k]=0;
                }
                break;
            }
        }

        //若第一列中有障碍物，即该格子为0，则后面的全修改为0（不可达）
        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0]==0){
                for(int k=i+1; k<m; k++){
                    obstacleGrid[k][0]=0;
                }
                break;
            }
        }

        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==0)
                    continue;
                else
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }

        return obstacleGrid[m-1][n-1];
    }
}
```
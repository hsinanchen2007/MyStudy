```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int res[][] = new int[m][n];
        res[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i-1 >= 0){
                    res[i][j] += res[i-1][j];
                }
                if(j-1 >=0){
                    res[i][j] += res[i][j-1];
                }
                if( obstacleGrid[i][j] == 1){
                    res[i][j] = 0;
                }
            }
        }
        return res[m-1][n-1];
    }
}
```

### 解题思路
这道题和不同路径1思路是一样的，但是其中有许多需要注意的地方。
1、第一行和第一列不能直接将其方法数初始化为1，因为假如是第一行的某个点前面有一个路障，那么无论怎么走他都无法到达路障后的点，第一列同理。
2、倘若只有一个点就是起始点start=finish，如果start上面没有路障，那么方法数为1而不是0。
3、倘若不止一个点，但是start上面有路障，那么无论怎么走方法数都是0。
4、倘若某一个点上面有路障，那么到达该点的方法肯定为0。
最后则是按照不同路径一上面的思路逐个考虑注意点即可。

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
       int m = obstacleGrid.length;
       int n = obstacleGrid[0].length;
       int num[][]=new int [m][n];
       if(m==1&&n==1&&obstacleGrid[0][0]==0)
       return 1;
       if(obstacleGrid[0][0]==1)
       return 0;
       for(int i = 0; i < m; i++){
           for(int j = 0; j < n; j++){
               if(i==0&&j==1||j==0&&i==1)
               num[i][j]=1;
               else if(i==0&&j==0)
               num[i][j]=0;
               else if(i==0&&j>1)
               num[i][j]=num[i][j-1];
               else if(j==0&&i>1)
               num[i][j]=num[i-1][j];
               else num[i][j]=num[i][j-1]+num[i-1][j];
               if(obstacleGrid[i][j]==1)
               num[i][j]=0;
               
           }
       }
       return num[m-1][n-1];
    }
}
```
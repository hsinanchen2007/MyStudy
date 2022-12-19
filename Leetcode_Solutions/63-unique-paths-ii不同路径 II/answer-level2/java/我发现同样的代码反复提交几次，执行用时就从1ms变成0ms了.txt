### 解题思路
![QQ截图20200316133616.png](https://pic.leetcode-cn.com/94643e15cbcd1abab21dca49d64856a63d364c0ced8cd5c0fef12a0c0e95f59b-QQ%E6%88%AA%E5%9B%BE20200316133616.png)

这波啊，这波是，肉蛋葱鸡

route_count[i][j]=route_count[i-1][j]+route_count[i][j-1]
和62题比，在填表之前加个判断条件就成了。当前格子不是障碍物时才用递归方程，否则为0

超简单的
### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        int [][] route_count=new int[m][n];
        if(obstacleGrid[0][0]==0) route_count[0][0]=1;


        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==0) route_count[i][0]=route_count[i-1][0];
        }
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]==0) route_count[0][j]=route_count[0][j-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0) route_count[i][j]=route_count[i-1][j]+route_count[i][j-1];
            }
        }
        return route_count[m-1][n-1];

    }
}
```
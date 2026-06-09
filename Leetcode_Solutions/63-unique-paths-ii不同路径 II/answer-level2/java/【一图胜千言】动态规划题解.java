


备注：
	红色方框表示障碍物，遇见障碍物当前格子的可能为0种
	如果当前格子不是障碍物，为左面+上面格子可能之和。

![image.png](https://pic.leetcode-cn.com/96142555fbbc9d6889b4e077fa2ecebe6dc7d91eaa3d38c8c25834f73714ad00-image.png)

代码：
```java
class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int cols = grid.length;
        int rows = grid[0].length;
        if(cols==0||rows==0||grid[0][0]==1){
            return 0;
        }
        int init=1;
        for(int i=0;i<rows;i++){
            if(grid[0][i]==1){
                init=0;
            }
            grid[0][i]=init;
        }
        init=1;
        for(int i=1;i<cols;i++){
            if(grid[i][0]==1){
                init=0;
            }
            grid[i][0]=init;
        }

        for(int row=1;row<rows;row++){
            for(int col=1;col<cols;col++){
                if(grid[col][row]==1){
                    grid[col][row]=0;
                }else{
                    grid[col][row]=grid[col-1][row]+grid[col][row-1];
                }
            }
        }
        
        return grid[cols-1][rows-1];
    }
}
```
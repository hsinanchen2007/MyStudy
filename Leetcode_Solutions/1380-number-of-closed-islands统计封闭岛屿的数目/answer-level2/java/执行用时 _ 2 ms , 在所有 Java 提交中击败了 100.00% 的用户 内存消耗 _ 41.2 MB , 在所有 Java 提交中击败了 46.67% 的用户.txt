### 解题思路
正常的深度优先遍历，如果判断陆地碰到了边，即 i==0||i==grid.length-1 ||j==0 ||j==grid[0].length-1，那么证明这个块陆地不满足情况，其他都满足。

### 代码

```java
class Solution {
    boolean isIsland;
    public int closedIsland(int[][] grid) {
        if(grid==null||grid.length==2||grid[0].length==2){
            return 0;
        }
        int count = 0;
        int columnNums =grid.length;
        for(int i=0;i<columnNums;i++){
            int[] row = grid[i];
            int rowNums = row.length;
            for(int j=0;j<rowNums;j++){
                int value = grid[i][j];
                if(value==0){
                    //当前是一块陆地 关联周围所有的区域 设为1
                    isIsland = true;
                    inject(grid,i,j);
                    if(isIsland){
                        count++;
                    }
                }
            }
        }
        return count;
    }
    public void inject(int[][] grid,int i,int j){
        grid[i][j]=1;
        if(i==0||i==grid.length-1 ||j==0 ||j==grid[0].length-1){
            isIsland = false;
        }
        if(i-1>=0 &&grid[i-1][j]==0){
            inject(grid,i-1,j);
        }
        if(j-1>=0 && grid[i][j-1]==0){
            inject(grid,i,j-1);
        }
        if(i+1<grid.length && grid[i+1][j]==0){
            inject(grid,i+1,j);
        }
        if(j+1<grid[0].length && grid[i][j+1]==0){
            inject(grid,i,j+1);
        }
    }
}
```
### 解题思路
找到最先腐烂的橘子，然后从这个橘子开始腐蚀周边的橘子，并且当被腐蚀后的橘子在腐蚀周边时，已经腐蚀的橘子val+1，这样就能找到最早腐蚀的橘子并且算出腐蚀天数；

### 代码

```java
class Solution {
    int grid[][];
    int l;
    int r;
    public int orangesRotting(int[][] grid) {
        if(grid.length==0){
           return -1;
        }
        this.r = grid.length;
        this.l = grid[0].length;
        this.grid = grid;   
        //找到每个腐烂的橘子
       for(int i=0;i<grid.length;i++){
           for(int j=0;j<grid[0].length;j++){
               if(grid[i][j]==2){
                   //调用下面写的算法使得周边的橘子腐烂
                   dps(i,j,2);
               }
           }
       }
       int max=0;
       for(int i=0;i<grid.length;i++){
           for(int j=0;j<grid[0].length;j++){
               if(grid[i][j]==1){
                   return -1;
               }
               //找到腐烂时间最久的橘子
               max=Math.max(grid[i][j],max);
           }
       }
             if(max==0){
                return 0;
               }
        return max-2;
    }
    public void dps(int i,int j,int val){
        //检索周边的橘子，看有没有已经腐烂的橘子，有的话val+1，如果有没腐烂的就val+1
        grid[i][j]=val;
        if (i > 0 && (grid[i - 1][j] == 1 || grid[i - 1][j] - grid[i][j] > 1)) {
            dps(i - 1, j, 1+val);
        }
        if (j > 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] - grid[i][j] > 1)) {
            dps(i, j - 1, 1+val);
        }
        if (i < r - 1 && (grid[i + 1][j] == 1 || grid[i + 1][j] - grid[i][j] > 1)) {
            dps(i + 1, j, 1+val);
        }
        if (j < l - 1 && (grid[i][j + 1] == 1 || grid[i][j + 1] - grid[i][j] > 1)) {
            dps(i, j + 1, 1+val);
        }
    }   
}
```
### 解题思路
此处撰写解题思路
1：通路
0：障碍

标记走过的路。

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int max =0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j] == 1){
                    max = Math.max(finds(grid,i,j),max);
                }
            }
        }
        return max;
    }
    public int finds(int[][] grid,int i,int j){
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0)
            return 0;
        grid[i][j] =0;
        int count =1;
        count += finds(grid,i+1,j);
        count +=finds(grid,i-1,j);
        count +=finds(grid,i,j+1);
        count += finds(grid,i,j-1);
        return count;
    } 
}
```
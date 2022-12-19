### 解题思路
此处撰写解题思路
沉岛思想
### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for(int i = 0; i<grid.length;i++){
            for(int j = 0; j < grid[i].length;j++){
                res = Math.max(res,dfs(i,j,grid));
            }
        }
        return res;
    }

    private int dfs(int i,int j,int[][] grid){
        if (i<0 || j < 0 || i>=grid.length || j>=grid[i].length || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        int sum = 1;
        sum += dfs(i+1,j,grid);
        sum += dfs(i-1,j,grid);
        sum += dfs(i,j+1,grid);
        sum += dfs(i,j-1,grid);
        return sum;
    }
}
```
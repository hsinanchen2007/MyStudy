### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                res = Math.max(res, bfs(i, j, grid));
            }
        }
        return res;
    }

    private int bfs(int i, int j, int[][] grid){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        int num = 1;
        num += bfs(i, j+1, grid);
        num += bfs(i, j-1, grid);
        num += bfs(i+1, j, grid);
        num += bfs(i-1, j, grid);
        return num;
    }
}
```
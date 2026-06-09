
![屏幕快照 2020-04-02 下午5.48.34.png](https://pic.leetcode-cn.com/26446075261e8b69a03080dedaebe17518d9636368fa2d66960187ecccaada16-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-02%20%E4%B8%8B%E5%8D%885.48.34.png)

### 解题思路
判断当前节点是否在边界(网格边界或连通分量边界)，利用深度优先搜索，访问上下左右位置。

### 代码

```java
class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) return grid;
        if (grid[r0][c0] == color) return grid;
        boolean[][] visited  = new boolean[grid.length][grid[0].length];
        dfs(grid, r0, c0, color, visited);
        return grid;
    }
    
    public void dfs(int[][] grid, int r, int c, int color, boolean[][] visited) {
        int pre = grid[r][c];
        if (r == 0 || c == 0 || r == grid.length - 1 || c == grid[0].length - 1) {
            grid[r][c] = color;
        }
        else {
            if (grid[r + 1][c] != pre && !visited[r + 1][c]) {
                grid[r][c] = color;
            } else if (grid[r - 1][c] != pre && !visited[r - 1][c]) {
                grid[r][c] = color;
            } else if (grid[r][c + 1] != pre && !visited[r][c + 1]) {
                grid[r][c] = color;
            } else if (grid[r][c - 1] != pre && !visited[r][c - 1]) {
                grid[r][c] = color;
            }
            
        }
        
        visited[r][c] = true;
        if (r + 1 < grid.length && grid[r + 1][c] == pre && !visited[r + 1][c]) {
            dfs(grid, r + 1, c, color, visited);
        }
        
        if (r - 1 >= 0 && grid[r - 1][c] == pre && !visited[r - 1][c]) {
            dfs(grid, r - 1, c, color, visited);
        }
        if (c + 1 < grid[0].length && grid[r][c + 1] == pre && !visited[r][c + 1]) {
            dfs(grid, r, c + 1, color, visited);
        }
        if (c - 1 >= 0 && grid[r][c - 1] == pre && !visited[r][c - 1]) {
            dfs(grid, r, c - 1, color, visited);
        }
    }
}
```
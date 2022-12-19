### 解题思路

深度搜索，需要节省空间没有使用额外的mark空间保存递归过程，而是在原图修改，每次节点被访问后置为2。

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        // dfs
        int res = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1)
                    res = Math.max(dfs(grid, i, j),res);
            }
        }
        return res;
    }

    private int dfs(int[][]grid, int x, int y){
        if(grid[x][y] == 0 || grid[x][y] == 2) return 0;
        else{
            // mark
            grid[x][y] = 2;
            int res = 1;
            if(x > 0) res += dfs(grid, x - 1, y);
            if(x < grid.length - 1) res += dfs(grid, x + 1, y);
            if(y > 0) res += dfs(grid, x, y - 1);
            if(y < grid[0].length - 1) res += dfs(grid, x, y + 1);
            return res;
        }
    }
}
```
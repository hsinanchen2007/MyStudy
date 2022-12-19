### 解题思路
核心思想
如果当前值为1，则这个1所在的大岛的面积就是1+上/下/左/右四个可能是岛的面积。
原则上需要一个isUsed[i][j]数组判断当前位置已被使用过，但此题中可以用将grid[i][j] = 0代替（一旦当前值使用过，则其他位置遍历时不能再使用此位置，这种情况和此位置为0没有区别。）

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int rows = grid.length;
        if(rows == 0){
            return 0;
        }
        int cols = grid[0].length;
        if(cols == 0){
            return 0;
        }
        //boolean[][] isUsed = new boolean[rows][cols];
        int max = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if( grid[i][j]==1){
                    int island = dfs(grid, i, j);
                    max = island > max ? island : max;
                }
            }
        }
        return max;
    }

    private int dfs(int[][] grid, int i, int j){
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0){
            return 0;
        }
        int res = 1;
        grid[i][j] = 0;
        res += dfs(grid, i+1, j);
        res += dfs(grid, i-1, j);
        res += dfs(grid, i, j+1);
        res += dfs(grid, i, j-1);
        return res;
    }

}
```

```java
class Solution {
    int grid[][];
    int r;
    int l;

    public int orangesRotting(int[][] grid) {
        if (grid.length == 0)
            return -1;
        this.r = grid.length;
        this.l = grid[0].length;
        this.grid = grid;   
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2) {      //烂橘子开始传染病毒
                    dps(i, j, 2);                      
                }
            }
        }
        int max = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1)    
                    return -1;            //有新鲜的橘子
                max = Math.max(grid[i][j], max);  //找到需要最多时间腐烂的橘子
            }
        }
        return max > 0 ? max - 2 : max;
    }

    public void dps(int i, int j, int val) {
        grid[i][j] = val;           //判断周围是新鲜的橘子或者是烂得更慢的橘子

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


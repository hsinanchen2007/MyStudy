考虑到题目中描述最多 25 个单元格中有黄金，我们可以遍历所有初始时有黄金的单元格，以此单元格为出发点向下递归，返回最大值即可。
下面是代码
代码块
```private int max = 0;
    public int getMaximumGold(int[][] grid) {
        for (int i = 0;i < grid.length;i++) {
            for (int j = 0;j < grid[0].length;j++) {
                if (grid[i][j] != 0) {
                    int temp = grid[i][j];
                    grid[i][j] = 0;
                    max = Math.max(max,get(i,j,grid) + temp);
                    grid[i][j] = temp;
                }
            }
        }
        return max;
    }
    public int get(int i,int j,int[][] grid) {
        int a = 0,b = 0, c = 0, d = 0;
        if (i+1 < grid.length && grid[i+1][j]!=0) {
            int temp = grid[i+1][j];
            grid[i+1][j] = 0;
            a = get(i+1,j,grid) + temp;
            grid[i+1][j] = temp;
        }
        if (j+1 < grid[0].length && grid[i][j+1]!=0) {
            int temp = grid[i][j+1];
            grid[i][j+1] = 0;
            b = get(i,j+1,grid) + temp;
            grid[i][j+1] = temp;
        }
        if (i-1 >= 0 && grid[i-1][j]!=0) {
            int temp = grid[i-1][j];
            grid[i-1][j] = 0;
            c = get(i-1,j,grid) + temp;
            grid[i-1][j] = temp;
        }
        if (j-1 >= 0 && grid[i][j-1]!=0) {
            int temp = grid[i][j-1];
            grid[i][j-1] = 0;
            d = get(i,j-1,grid) + temp;
            grid[i][j-1] = temp;
        }
        return Math.max(Math.max(a,b),Math.max(c,d));```
注意到我们不能让矿工在两个单元格之间来回走动(这样会导致结果变为无穷大)，我们将已经走过的单元格赋值为0，递归完成后恢复即可。
递归的过程即为bfs.

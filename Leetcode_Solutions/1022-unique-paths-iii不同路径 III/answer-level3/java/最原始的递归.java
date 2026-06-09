官方题解用了比较巧妙地方法，下面是最原始的递归解法，效率并不高但好在逻辑简单。确定状态转移方程后判断边界条件，作为入门解法可在此基础上进一步进行优化：
```java []
/**
     * 递归解法
     *
     * @param grid
     * @return
     */
    public static final int uniquePathsIII(int[][] grid) {
        if (grid == null) {
            return 0;
        }
        int x = grid.length;
        int y = grid[0].length;
        int m = 0;
        int n = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] == 2) {
                    m = i;
                    n = j;
                }
            }
        }
        int[][] cache = new int[x][y];
        int re = uniquePaths1(m, n, grid);
        System.out.print("  " + cache[m][n]);
        return re;
    }

    /**
     * 递归解法
     *
     * @param m
     * @param n
     * @param grid
     * @return
     */
    public static final int uniquePaths1(int m, int n, int[][] grid) {
        int x = grid.length;
        int y = grid[0].length;
        int flag = 0;
        int endflag = 0;
        /*减越界*/
        if (m < 0 || n < 0) {
            return 0;
        }
        /*加越界*/
        if (m > x - 1 || n > y - 1) {
            return 0;
        }
        /*路线不通*/
        if (grid[m][n] == -1) {
            return 0;
        }
        /*到达终点*/
        if (grid[m][n] == 1) {
            int isAllFlag = 0;
            /*是否全部走完*/
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (grid[i][j] == 0) {
                        isAllFlag = 1;
                    }
                }
            }
            /*未走完全部0不是有效路径*/
            if (isAllFlag == 1) {
                return 0;
            }
            return 1;
        }
        /*走过路径标识为不可重复经过*/
        if (grid[m][n] == 0) {
            grid[m][n] = -1;
            flag = 1;
        }
        /*终点不可经过*/
        if (grid[m][n] == 2) {
            grid[m][n] = -1;
            endflag = 1;
        }
        /*状态转移计算*/
        int re = uniquePaths1(m - 1, n, grid) + uniquePaths1(m, n - 1, grid)
                    + uniquePaths1(m + 1, n, grid) + uniquePaths1(m, n + 1, grid);
        /*恢复现场-已走过路径*/
        if (flag == 1) {
            grid[m][n] = 0;
        }
        /*恢复现场-终点*/
        if (endflag == 1) {
            grid[m][n] = 2;
        }
        return re;
    }
```


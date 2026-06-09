视频地址：https://www.youtube.com/watch?v=SpMez87v0O8
视频里是用C++实现的，这里改用了java实现，并且去掉了visit，改用grid自身保存访问信息

```
class Solution {

    // 下标0, 1, 2, 3分别代表下、上、右、左
    int[][] d = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // 数值1, 2, 4, 8分别代表下、上、右、左（分别为1左移0、1、2、3位，与d对应）
    // 数组t表示每种网格值可以去到的方向
    // 例如下标0(网格值为1)可以去到的方向是左右，分别为8和4
    int[] t = new int[]{4|8, 1|2, 1|8, 1|4, 2|8, 2|4};

    public boolean hasValidPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        return dfs(grid, m, n, 0, 0);
    }

    private boolean dfs(int[][] grid, int m, int n, int x, int y) {
        if (x == m - 1 && y == n - 1) {
            return true;
        }
        int c = grid[x][y];
        // 将grid[x][y]置0表示访问过
        grid[x][y] = 0;
        // 遍历4个方向
        for (int i = 0; i < 4; ++i) {
            // 用来判断当前网格能否向i方向前进
            if ((t[c - 1] >> i & 1) == 0) {
                continue;
            }
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx == m || ny < 0 || ny == n || grid[nx][ny] == 0) {
                continue;
            }
            // 对i方向取反方向
            int j = i ^ 1;
            // 用来判断下一个网格能否向i的反方向前进
            if ((t[grid[nx][ny] - 1] >> j & 1) == 0) {
                continue;
            }
            if (dfs(grid, m, n, nx, ny)) {
                return true;
            }
        }
        return false;
    }
}
```

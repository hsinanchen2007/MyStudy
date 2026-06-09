### 解题思路
![屏幕快照 2020-02-06 15.44.40.png](https://pic.leetcode-cn.com/af2e075c6e2f1b3a8057e78c74d1f26ae2b7cec73dddb61aef80803a490f4a87-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-06%2015.44.40.png)


### 代码

```java
class Solution {

    /**
     * 寻路矩阵尺寸
     */
    private static int m, n;
    /**
     * 访问标记
     */
    private static boolean[][] visited;
    /**
     * 寻路方向四方向
     */
    private static int[][] d = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        m = grid.length;
        n = grid[0].length;
        visited = new boolean[m][n];
        dfs(grid, r0, c0, color);
        return grid;
    }

    private void dfs(int[][] grid, int r0, int c0, int color) {
        visited[r0][c0] = true;
        int oldColor = grid[r0][c0];
        if (oldColor == color) {
            return;
        }
        grid[r0][c0] = color;
        // 标记当前值,是否需要重置回原本的颜色
        boolean reColor = true;
        for (int i = 0; i < d.length; i++) {
            int nex = r0 + d[i][0];
            int ney = c0 + d[i][1];
            // 如果能够越界就证明当前在边界，一定要染色
            if (!inArea(nex, ney)) {
                reColor = false;
                continue;
            }
            if (!visited[nex][ney] && grid[nex][ney] == oldColor) {
                dfs(grid, nex, ney, color);
            } 
            // 只要有一个值不能进入循环 且 没被访问过，那么这里也是边框
            else if (!visited[nex][ney]) {
                reColor = false;
            }
        }
        // 不是边框不将颜色标记回去
        if (reColor) {
            grid[r0][c0] = oldColor;
        }
    }

    private boolean inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}
```
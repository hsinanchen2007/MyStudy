### 解题思路
DFS加两个二维数组缓存到达当前位置最小的步数，因为形态不一样，平行的步数，也有垂直的步数。
这样就实现了剪枝的操作。

![image.png](https://pic.leetcode-cn.com/b48ff647a4d19000510c632e2c4097131c5e782fadcde9223226af134948f5a1-image.png)


### 代码

```java
class Solution {
    public int minimumMoves(int[][] grid) {
        int[][] h = new int[grid.length][];
        int[][] v = new int[grid.length][];
        for (int i = 0; i < grid.length; i++) {
            h[i] = new int[grid[0].length];
            v[i] = new int[grid[0].length];
            Arrays.fill(h[i], -1);
            Arrays.fill(v[i], -1);
        }
        dfs(grid, h, v, 0, 0, 0, 1, 0);
        return h[grid.length - 1][grid[0].length - 1];
    }

    private void dfs(int[][] grid, int[][] h, int[][] v, int x, int y, int xc, int yc, int count) {
        if (x == xc && h[xc][yc] >= 0 && h[xc][yc] <= count) {
            return;
        }
        if (y == yc && v[xc][yc] >= 0 && v[xc][yc] <= count) {
            return;
        }
        if (x == xc) {
            h[xc][yc] = count;
        }
        if (y == yc) {
            v[xc][yc] = count;
        }

        if (yc < grid[0].length - 1 && grid[xc][yc + 1] == 0 && grid[x][y + 1] == 0) {
            dfs(grid, h, v, x, y + 1, xc, yc + 1,count + 1);
        }
        if (xc < grid.length - 1 && grid[x + 1][y] == 0 && grid[xc + 1][yc] == 0)
            dfs(grid, h, v, x + 1, y, xc + 1, yc, count + 1);
        if (x == xc && x < grid.length - 1 && grid[x + 1][y] == 0 && grid[xc + 1][yc] == 0)
            dfs(grid, h, v, x, y, x + 1, y, count + 1);
        if (y == yc && y < grid[x].length - 1 && grid[x][y + 1] == 0 && grid[xc][yc + 1] == 0)
            dfs(grid, h, v, x, y, x, y + 1, count + 1);
    }
}
```
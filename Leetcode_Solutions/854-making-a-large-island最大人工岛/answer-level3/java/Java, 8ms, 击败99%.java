遍历这个矩阵中的每个点, 如果是0, 则计算该点上下左右的连通块面积. 
注意,连通块本身的面积也要与最大值进行一次比较, 比如像{{1}}这种情况.
计算联通块面积时打个标记, 表示已计算过, 记入rem数组. 标记单调变化即可, 这里从-1开始, 一直递减.
```
class Solution {
    int[] rem;
    int flag;
    int[][] direction = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };//上,右,下,左

    public int largestIsland(int[][] grid) {
        int n = grid.length;
        this.rem = new int[n * n / 2 + 2];
        this.flag = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans = Math.max(ans, 1 + aroundSSum(grid, n, i, j));
                } else if (grid[i][j] == 1) {
                    int temp = coloring(grid, n, i, j);
                    flag--;
                    ans = Math.max(ans, temp);
                }
            }
        }
        return ans;
    }

    private int aroundSSum(int[][] grid, int n, int x, int y) {
        if (!lessThanN(x, n) || !lessThanN(y, n))
            return 0;
        Set<Integer> fSet = new HashSet<>();
        int s = 0;
        for (int i = 0; i < 4; i++) {
            int dx = x + direction[i][0];
            int dy = y + direction[i][1];
            if (lessThanN(dx, n) && lessThanN(dy, n)) {
                if (grid[dx][dy] == 0) {
                    continue;
                } else if (grid[dx][dy] == 1) {
                    coloring(grid, n, dx, dy);
                    flag--;
                }
                if (!fSet.contains(grid[dx][dy])) {
                    s += rem[-grid[dx][dy]];
                    fSet.add(grid[dx][dy]);
                }
            }
        }
        return s;
    }

    private boolean lessThanN(int p, int n) {
        return p >= 0 && p < n;
    }

    private int coloring(int[][] grid, int n, int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n) {
            return 0;
        }
        if (grid[x][y] == 0 || grid[x][y] != 1)
            return 0;
        else {
            grid[x][y] = flag;
            int s = 1 + coloring(grid, n, x - 1, y) + coloring(grid, n, x, y + 1)
                    + coloring(grid, n, x + 1, y) + coloring(grid, n, x, y - 1);
            rem[-flag] = s;
            return s;
        }
    }
}
```

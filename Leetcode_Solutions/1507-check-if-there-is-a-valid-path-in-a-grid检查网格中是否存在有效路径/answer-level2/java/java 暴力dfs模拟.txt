### 思路
每个单元格下一步要走向哪，依据的是当前单元格的数字(1~6),而且，能不能到达当前单元格指向的两个方向的下一个单元格，又依赖于下一个单元格是否有口与当前单元格连通，举个例子吧。假设当前单元格是1，那么可以往左走，也可以往右走，如果往左走的话，则只有(1, 4, 6)可以接的上去。右边与其他数字同理。
<br/>

```java
 private int m;
    private int n;
    private int[][] grid;
    private boolean[][] used;

    private boolean isLeftOk(int i, int j) {
        return j > 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6);
    }

    private boolean isRightOk(int i, int j) {
        return j + 1 < n && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5);
    }

    private boolean isTopOk(int i, int j) {
        return i > 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4);
    }

    private boolean isBottomOk(int i, int j) {
        return i + 1 < m && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6);
    }

    private boolean dfs(int i, int j) {
        if (used[i][j]) {
            return false;
        }

        if (i == m - 1 && j == n - 1) {
            return true;
        }

        used[i][j] = true;
        int val = grid[i][j];

        if (val == 1) {
            return isLeftOk(i, j) && dfs(i, j - 1) || isRightOk(i, j) && dfs(i, j + 1);
        } else if (val == 2) {
            return isTopOk(i, j) && dfs(i - 1, j) || isBottomOk(i, j) && dfs(i + 1, j);
        } else if (val == 3) {
            return isLeftOk(i, j) && dfs(i, j - 1) || isBottomOk(i, j) && dfs(i + 1, j);
        } else if (val == 4) {
            return isRightOk(i, j) && dfs(i, j + 1) || isBottomOk(i, j) && dfs(i + 1, j);
        } else if (val == 5) {
            return isLeftOk(i, j) && dfs(i, j - 1) || isTopOk(i, j) && dfs(i - 1, j);
        }

        return isTopOk(i, j) && dfs(i - 1, j) || isRightOk(i, j) && dfs(i, j + 1);
    }

    public boolean hasValidPath(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        used = new boolean[m][n];
        return dfs(0, 0);
    }
```
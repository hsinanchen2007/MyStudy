![image.png](https://pic.leetcode-cn.com/843a8b25a429edadf1bedc67c6cbb36a03dd9843ec93c64953eb953996a5bc5e-image.png)


```
//往上下左右四个方向走时x和y坐标的变化情况
    private int[][]dirs = new int[][] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    //每种类型的街道可以走的方向, 从1开始
    private int[][]memos = new int[][] {{-1, -1}, {2, 3}, {0, 1}, {1, 2}, {1, 3}, {0, 2}, {0, 3}};
    //往上下左右走时，对应的单元格可以匹配的街道类型
    private int[][]matches = new int[][] {{2, 3, 4}, {2, 5, 6}, {1, 4, 6}, {1, 3, 5}};
    private int rows = 0;
    private int cols = 0;

    public boolean hasValidPath(int[][] grid) {
        rows = grid.length;
        cols = grid[0].length;

        int[][]visited = new int[rows][cols];
        return dfs(grid, 0, 0, visited);
    }

    public boolean dfs(int[][] grid, int x, int y, int[][] visited) {
        if (x == rows - 1 && y == cols - 1) {
            return true;
        }

        visited[x][y] = 1;



        //每种类型的街道可以走的方向
        int[]memoDirs = memos[grid[x][y]];
        int newDir = -1;
        //尝试新的方向是否可走，这里主要是判断坐标的合法性以及不往回走
        for (int memoDir : memoDirs) {
            int newX = x;
            int newY = y;

            newX += dirs[memoDir][0];
            newY += dirs[memoDir][1];

            if (isValidPos(grid, newX, newY) && visited[newX][newY] == 0) {
                newDir = memoDir;
                x = newX;
                y = newY;
                break;
            }
        }

        if (newDir == -1) {
            return false;
        }
        //判断新的位置上的街道类型是否可以进入，可以则继续递归
        int[] matchStreetTypes = matches[newDir];
        for (int matchStreetType : matchStreetTypes) {
            if (grid[x][y] == matchStreetType) {
                return dfs(grid, x, y, visited);
            }
        }

        return false;
    }

    private boolean isValidPos(int[][] grid, int i , int j) {
        int rows = grid.length;
        int cols = grid[0].length;

        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
```

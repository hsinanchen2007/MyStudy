经典DFS，用标记的思路，只要有一个点是岛屿，与之相邻的岛标记后不再计数。
回溯后，不消除标记。
不能用boolean，会出现短路异常，如下

class Solution {
    public int num = 0;

    public int numIslands(char[][] grid) {
        for (int x = 0; x < grid.length; x++) {
            for (int y = 0; y < grid[0].length; y++) {
                if (dfs(x, y, grid)) {
                    num++;
                }
            }
        }
        return num;
    }

    public static boolean dfs(int x, int y, char[][] grid) {
        if (x <= -1 || y <= -1 || x >= grid.length || y >= grid[0].length || grid[x][y] != '1') {
            return false;
        }
        boolean result = false;
        if (grid[x][y] == '1') {
            grid[x][y] = '2';
            result = true;
        }
        result = dfs(x + 1, y, grid)
                || dfs(x - 1, y, grid)
                || dfs(x, y + 1, grid)
                || dfs(x, y - 1, grid)
                || result;
        return result;
    }
}



```
package com.leetcode.LT200;

public class LT200 {
    public static void main(String[] args) {
        char[][] grid = {{'1', '1', '1'}, {'0', '1', '0'}, {'0', '1', '0'}};
        Solution solution = new Solution();
        System.out.println(solution.numIslands(grid));
    }
}

class Solution {
    public int num = 0;

    public int numIslands(char[][] grid) {
        for (int x = 0; x < grid.length; x++) {
            for (int y = 0; y < grid[0].length; y++) {
                if (grid[x][y] == '1') {
                    num++;
                    dfs(x, y, grid);
                }
            }
        }
        return num;
    }

    public static void dfs(int x, int y, char[][] grid) {
        if (x <= -1 || y <= -1 || x >= grid.length || y >= grid[0].length || grid[x][y] != '1') {
            return;
        }
        grid[x][y] = '2';
        dfs(x + 1, y, grid);
        dfs(x - 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
        return;
    }
}

```

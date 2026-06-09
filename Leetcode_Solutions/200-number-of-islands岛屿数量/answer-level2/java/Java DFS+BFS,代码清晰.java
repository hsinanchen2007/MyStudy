# 思路
基本思路就是遍历二维数组，如果遇到1，就进行DFS或者BFS，与这个1相连的都是陆地。遍历的时候，count++，等遍历完毕，返回count数量，就是岛屿的数量

# 值得注意的点
1.这是一道典型的图上的DFS或者BFS，可以多练习几遍。
2.有一个用例是[]，二维数组入参先判断行数为0，直接返回0，然后再去取列数。
3.用另外值'2'来防止被重复访问。
4.BFS用一个int[]类型的数组来存储陆地的坐标（即'1'的坐标），例如{{0,1}，{1,2},{1,1}}
5.可以结合代码看下DFS和BFS的差异。

# 代码
DFS：
```
class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        if (m == 0) {
            return 0;
        }
        int n = grid[0].length;
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    private void dfs(char[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] != '1') {
            return; //递归的终止条件，包含了边界值。以及撞墙值。
        } else {
            grid[i][j] = '2';
        }
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
}
```

BFS：
```
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        if (m == 0) {
            return 0;
        }
        int n = grid[0].length;

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }

    private void bfs(char[][] grid, int i, int j) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{i, j});
        while (!queue.isEmpty()) {
            int[] position = queue.poll();
            int r = position[0];
            int c = position[1];
            if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                grid[r - 1][c] = '2';
                queue.add(new int[]{r - 1, c});
            }
            if (r + 1 <= grid.length - 1 && grid[r + 1][c] == '1') {
                grid[r + 1][c] = '2';
                queue.add(new int[]{r + 1, c});
            }
            if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                grid[r][c - 1] = '2';
                queue.add(new int[]{r, c - 1});
            }
            if (c + 1 <= grid[0].length - 1 && grid[r][c + 1] == '1') {
                grid[r][c + 1] = '2';
                queue.add(new int[]{r, c + 1});
            }
        }
    }
}
```



# Flood fill算法（染色）
Flood fill是从一个区域中找出相连通的点与其他相连通的区域区分开的经典算法，因其思路类似洪水从一个区域扩散到所有能到达的区域而得名。在扫雷中，Flood fill算法被用于计算应清除的区域。

Flood fill算法接收三个参数：起始点，目标颜色和替换颜色。寻找与起始节点相连通的目标颜色节点，将其颜色改变为替换颜色。

## DFS遍历

```
class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        int result = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
    
    private void dfs(char[][] grid, int i, int j) {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (i + 1 < grid.length && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if (j + 1 < grid[0].length && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
}
```
时间复杂度：for循环一次遍历，染色过程最差情况下所有节点均为1，全部遍历，共O(M*N)。
空间复杂度：最差情况下所有节点均连通，一条dfs路径遍历所有节点，递归调用深度M*N。

## BFS遍历

```
class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        int result = 0;
        int l = grid.length;
        int w = grid[0].length;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    q.offer(i * w + j); // 通过i * w + j保存当前点位置并入队
                    grid[i][j] = '0';   // 已入队过的节点要标记已入队，避免重复入队
                    while (!q.isEmpty()) {
                        int cur = q.poll();
                        int row = cur / w;  // 分解坐标
                        int col = cur % w;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                            q.offer(cur - w);
                            grid[row - 1][col] = '0';   // 入队的同时标记已入队
                        }
                        if (row + 1 < l && grid[row + 1][col] == '1') {
                            q.offer(cur + w);
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                            q.offer(cur - 1);
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < w && grid[row][col + 1] == '1') {
                            q.offer(cur + 1);
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }
        return result;
    }
}
```
时间复杂度：同上O(M*N)。
空间复杂度：O(min(M,N))。最差情况下队列最大长度可能达到min(M,N)或者min(M,N)+1，取决于上下左右相邻节点的遍历方向。
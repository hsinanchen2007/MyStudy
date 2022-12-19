### 解题思路
$grid[x][y]$
* 0: 水域
* 1: 陆地
* 2: 已经遍历过的陆地

从图中可以看出来，如果无法访问相邻的节点，那么就遇到了一个边界，这时候周长就需要加1。
![Screen Shot 2020-03-16 at 21.08.29.png](https://pic.leetcode-cn.com/708b3be4d989e0f3efa304295f58bc35381ca451550524b4a0052d55485bde58-Screen%20Shot%202020-03-16%20at%2021.08.29.png)

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        for (int x = 0; x < grid.length; ++x) {
            for (int y = 0; y < grid[0].length; ++y) {
                if (grid[x][y] == 1) { //只有一个岛屿，找到了就直接返回
                    return dfs(grid, x, y);
                }
            }
        }
        return 0;
    }

    private int dfs(int[][] grid, int x, int y) {
        grid[x][y] = 2;
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        int preimeter = 0;
        for (int k = 0; k < dx.length; ++ k) {
            int adjX = x + dx[k];
            int adjY = y + dy[k];
            // 边界
            if (adjX < 0 || adjX >= grid.length || adjY < 0 || adjY >= grid[0].length) {
                ++ preimeter;
                continue;
            }
            if (grid[adjX][adjY] == 0) {
                ++ preimeter;
                continue;
            }
            if (grid[adjX][adjY] == 1) 
                preimeter += dfs(grid, adjX, adjY);
                
        }
        return preimeter;
    }
}
```
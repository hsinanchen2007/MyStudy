### 解题思路
DFS的经典题？

二重循环遍历地图，找出岛屿，开始对该岛DFS，求其面积，并维护一个全局最大面积，最后返回它

DFS函数：面积+1，同时把该土地变为海洋，然后对上下左右的邻居土地再做DFS，将面积整合起来

### 代码

```java
class Solution {
    int m;
    int n;
    int[] dx;
    int[] dy;
    
    public int maxAreaOfIsland(int[][] grid) {
        m = grid.length;
        if(m == 0) {
            return 0;
        }
        n = grid[0].length;
        dx = new int[] {0, 0, 1, -1};
        dy = new int[] {1, -1, 0, 0};
        int maxArea = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    maxArea = Math.max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
    
    public int dfs(int[][] grid, int x, int y) {
        int area = 1;
        grid[x][y] = 0;
        for(int i=0; i<4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]==1) {
                area += dfs(grid, xx, yy);
            }
        }
        return area;
    }
}
```
### 解题思路
![image.png](https://pic.leetcode-cn.com/b2ca6116c7e02722283295d28382fbbfd0c7dd98b60fb0ef7080732789f7df0e-image.png)

联通分量内节点的颜色记为sColor，染边框的颜色为tColor。 （source color 与 target color）
dfs遍历整个联通分量：
1. 对于遍历过的节点，我们都让他们的值为负数，这样，就不需要多开空间来记录节点是否遍历过
2. 对于联通分量中内部的节点，他们的值都为sColor，遍历过后，他们的值为-sColor。
3. 对于联通分量边框上的节点，他们的值都为sColor，遍历过后，他们的值为-tColor。
4. 遍历完整个联通分量，将整个grid中的负值改为正值

关键在于怎么判断一个节点在联通分量中是否处于边框的位置：
1. 该节点在整个网格的四周:
```
x == 0 || x+1 >= g.length || y == 0 || y+1 >= g[0].length
```
2. 该节点的↑↓←→节点有任意一个节点不属于当前联通分量；对于周围某个节点的颜色nextColor，如果它满足如下条件，那么他就不属于当前联通分量
```
nextColor != sColor && nextColor != -sColor && nextColor != -tColor
```
- nextColor != sColor：颜色上看根本不属于当前联通分量
- nextColor != -sColor：它不是已经遍历过的联通分量内部节点
- nextColor != -tColor：它不是已经遍历过的联通分量边框节点
### 代码
```java
class Solution {
    // 访问↑↓←→节点时坐标x, y的偏移量
    private int[][] dis = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        dfs(grid, r0, c0, grid[r0][c0], color);
        // 将负值置为正值
        for(int i = 0 ; i < grid.length ; i++) {
            for(int j = 0 ; j < grid[i].length ; j++) {
                grid[i][j] = grid[i][j] > 0 ? grid[i][j] : -grid[i][j];
            }
        }
        return grid;
    }

    private void dfs(int[][] g, int x, int y, int sColor, int tColor) {
        // 越界 || 不属于同一个联通分量 || 被访问过
        if(x < 0 || x >= g.length ||
           y < 0 || y >= g[0].length ||
           g[x][y] != sColor || g[x][y] < 0) {
            return;
        }

        // 当前节点已经被访问，设置负值
        g[x][y] = -sColor;

        // 判断边界
        if(x == 0 || x+1 >= g.length ||
           y == 0 || y+1 >= g[0].length) {
            // 区域边界
            g[x][y] = -tColor;
        } else {
            // 连通分量的边界
            for(int i = 0 ; i < dis.length ; i++) {
                int nextColor = g[x + dis[i][0]][y + dis[i][1]];
                // 这里是关键点
                if(nextColor != sColor && nextColor != -sColor && nextColor != -tColor) {
                    g[x][y] = -tColor;
                    break;
                }
            }
        }

        // 深度优先搜索，继续
        for(int i = 0 ; i < dis.length ; i++) {
            dfs(g, x+dis[i][0], y+dis[i][1], sColor, tColor);
        }
    }
}
```
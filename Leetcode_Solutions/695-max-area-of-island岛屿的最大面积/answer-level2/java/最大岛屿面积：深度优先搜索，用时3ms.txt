### 解题思路
遍历二位数组，当找到值为1时，进行深度优先遍历，定义一个数组记录上下左右四个方向，来判断该值其四个方向上是否有数值为1，当数组为1时，并对该位置进行深度优先搜索，并更新该值为0，以免回溯时重复遍历，定义一个num数来记录在遍历过程中1的个数。

### 代码

```java
class Solution {
   int[][] direction = {{-1,0},{0,-1},{0,1},{1,0}};
    int m,n,num;
    public int maxAreaOfIsland(int[][] grid) {
        m = grid.length; // 行
        n = grid[0].length; //列
        num = 0;
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    num++;
                    dfs(i, j, grid);
                }
                if(num > max) max = num;
                num = 0;
            }
        }
        return max;
    }

    private void dfs(int i, int j, int[][] grid) {
        for (int k = 0; k < 4; k++) {
            int x = i + direction[k][0];
            int y = j + direction[k][1];
            if(judge(x,y) && grid[x][y] == 1) {
                grid[x][y] = 0;
                num++;
                dfs(x,y,grid);
            }
        }
    }

    private boolean judge(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}
```
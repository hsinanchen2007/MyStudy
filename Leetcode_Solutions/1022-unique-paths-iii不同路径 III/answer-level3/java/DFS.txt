### 解题思路
1. 首先遍历grid，找出起始位置和结束位置
2. 统计0的数目为cnt
3. 代码出口就是即将探测的点是终点，并且此时经过的零点的数目为cnt

### 代码

```java
class Solution {
    public int uniquePathsIII(int[][] grid) {
        int[] res = new int[1];
        int[] start = new int[2];
        int[] end = new int[2];
        int[][] vector = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
        int[][] visited = new int[grid.length][grid[0].length];
        int cnt = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 0)
                    cnt++;
                else if (grid[i][j] == 1){
                    start[0] = i;
                    start[1] = j;
                }
                else if (grid[i][j] == 2){
                    end[0] = i;
                    end[1] = j;
                }
            }
        }
        visited[start[0]][start[1]] = 1;
        dfs(grid, visited, cnt, 0, start[0], start[1], end[0],end[1],res,vector);
        return res[0];
    }

    private void dfs(int[][] grid, int[][] visited,int zeroCnt,int current, int i, int j, int t_i, int t_j, int[] res,int[][] vector){
        if (i == t_i && j == t_j && current == zeroCnt){
            res[0]++;
            return;
        }
        if (grid[i][j] == 0)
            current++;
        for (int[] ints : vector) {
            int a = ints[0] + i;
            int b = ints[1] + j;
            if (a >= 0 && a < grid.length && b >= 0 && b < grid[0].length){
                if (visited[a][b] == 0 && grid[a][b] != -1){
                    visited[a][b] = 1;
                    dfs(grid, visited,zeroCnt, current,a,b,t_i,t_j,res,vector);
                    visited[a][b] = 0;
                }
            }
        }
    }
}
```
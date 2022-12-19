### 解题思路
bfs思路

### 代码

```java
class Solution {

    //存方向数组
    public int[][] dir = {{-1, 0}, {0 , -1}, {1, 0}, {0, 1}};

    //存是否遍历了数组
    public boolean[][] isArrive;

    public int numIslands(char[][] grid) {
        
        //行
        int rows = grid.length;

        if (rows == 0) {
            return 0;
        }
        
        //列
        int cols = grid[0].length;

        //是否访问过数组
        isArrive = new boolean[rows][cols];

        //isLand数量
        int isLandCnt = 0;

        //依次进行查找
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!isArrive[i][j] && grid[i][j] == '1') {
                    isLandCnt++;
                    //dfs深度遍历寻找相联通的陆地
                    dfs(grid, i, j);
                }
            }
        }

        return isLandCnt;
    }

    //对节点i，j进行dfs遍历
    private void dfs(char[][] grid, int i, int j) { 
        
        //赋值已访问过
        isArrive[i][j] = true;
    
        //四个方向上分别进行dfs查重
        for (int k = 0; k < dir.length; k++) {
            int newi = i + dir[k][0];
            int newj = j + dir[k][1];
            if (isArea(grid, newi, newj) && !isArrive[newi][newj] && grid[newi][newj] == '1') {
                dfs(grid, newi, newj);
            }  
        }
    }

    private boolean isArea(char[][] grid, int i, int j) {
        //bad-case
        if (i < 0 || i > grid.length-1 || j < 0 || j > grid[0].length-1) {
            return false;
        } 
        return true;
    }
}
```
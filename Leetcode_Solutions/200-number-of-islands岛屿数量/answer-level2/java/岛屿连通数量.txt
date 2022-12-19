### 解题思路
染色方法,将所有1的连通小岛周围都变为0,统计个数  + DFS

### 代码

```java
class Solution {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length==0) { 
            return 0;
        }
        
        int maxX =grid.length;
        int maxY =grid[0].length;

        int count = 0;

        for (int x = 0; x < grid.length; x++) {
            for (int y = 0; y < grid[0].length; y++) {
                count += floolFill(grid, x,y,maxX,maxY);
            }
        }

        return count;
    }

      private int floolFill(char[][] grid, int x,int y,int maxX,int maxY) {
        if(!isValide(grid,x,y,maxX,maxY))
        {
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            floolFill(grid, x+dx[i], y+dy[i], maxX, maxY);
        }

        return 1;
    }

    private boolean isValide(char[][] grid,int x,int y,int maxX,int maxY) {
        //判断边界值是否合法
        if(x<0 || x>=maxX || y<0 || y>=maxY){
            return false;
        }

        if(grid[x][y]=='0')
        {
            return false;
        }
        else {
            grid[x][y] = '0';
            return true;
        }
    }
}
```
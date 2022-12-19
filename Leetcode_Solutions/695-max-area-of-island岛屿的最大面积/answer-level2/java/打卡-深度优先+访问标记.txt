### 解题思路
深度优先+访问标记，循环访问每一点，如果是陆地，标记已访问，面积加1，然后访问相邻岛屿，用max保存最大面积

### 代码

```java
class Solution {
    boolean[][] visited;
    int[][] grid;
    public int maxAreaOfIsland(int[][] grid) {
        if(grid.length == 0 || grid[0].length == 0){
            return 0;
        }
        this.grid = grid;
        visited = new boolean[grid.length][grid[0].length];

        int max = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    max = Math.max(max, area(i, j));
                }
            }
        }

        return max;
    }

    int area(int x, int y){
        if(x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y] == 1 && !visited[x][y]){
            visited[x][y] = true;
            return 1 + area(x - 1, y) + area(x + 1, y) + area(x, y - 1) + area(x, y + 1);
        }
        
        return 0;
    }
}
```
### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<int[]> queue = new ArrayDeque<>();
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        boolean flag = true;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1) {
                    flag = false;
                }
                if(grid[i][j] == 2) {
                    queue.offer(new int[]{i,j});
                }
            }
        }
        if(flag) {
            return 0;
        }        
        int[] res = null;
        while(!queue.isEmpty()) {
            res = queue.poll();
            int x = res[0];
            int y = res[1];
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx < 0 || newx >=grid.length || newy < 0 || newy >= grid[x].length
                 || grid[newx][newy] != 1) {
                    continue;
                }
                grid[newx][newy] = grid[x][y] + 1;
                queue.offer(new int[]{newx,newy});
            }
        }
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return grid[res[0]][res[1]] - 2;
    }

}
```
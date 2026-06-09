### 解题思路
先把所有烂橘子加入了队列 然后对所有烂橘子BFS 用到第一个烂橘子的距离来记录时间

### 代码

```java
class Solution {

    private static final List<int[]> DIRECTIONS = Arrays.asList(
        new int[] { 1,  0},
        new int[] {-1,  0},
        new int[] { 0,  1},
        new int[] { 0, -1}
    );

    public int orangesRotting(int[][] grid) {
        
        Queue<int[]> q = new LinkedList<>();

        if(grid.length == 0) return -1;

        for(int r = 0; r < grid.length; r++){
            for(int c = 0; c < grid[0].length; c++){
                if(grid[r][c] == 2){
                    q.add(new int[] {r, c});
                }
            }
        }

        int time = 0;

        while(!q.isEmpty()){

            int[] point = q.poll();
            int row = point[0];
            int col = point[1];

            for(int[] direction : DIRECTIONS){

                int r = row + direction[0];
                int c = col + direction[1];
                if(r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == 0 || grid[r][c] >= 2) continue;
                if(grid[r][c] == 1) {
                    grid[r][c] = grid[row][col] + 1;
                    if(grid[r][c] >= time) time = grid[r][c];
                }
                q.add(new int[] {r, c});
            }
        }
        for(int r = 0; r < grid.length; r++){
            for(int c = 0; c < grid[0].length; c++){
                if(grid[r][c] == 1) return -1;
            }
        }

        int res = time - 2;
        if(res <= 0) return 0;
        else return res;
    }
}
```
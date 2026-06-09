### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int[] dx = new int[]{0, 0, 1, -1};
        int[] dy = new int[]{1, -1, 0, 0};
        Queue<Integer[]> queue = new ArrayDeque<>();
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1){
                    queue.offer(new Integer[]{i, j});
                }
            }
        }

        boolean hasOcean = false;
        Integer [] point = null;
        while(!queue.isEmpty()){
            point = queue.poll();
            int x = point[0];
            int y = point[1];
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX < 0 || newX >= grid.length || newY < 0 || newY >= grid[0].length || grid[newX][newY] != 0){
                    continue;
                }
                hasOcean = true;
                queue.offer(new Integer[]{newX, newY});
                grid[newX][newY] = grid[x][y] + 1;
            }
        }

        if(hasOcean == false || point == null){
            return -1;
        }

        return grid[point[0]][point[1]] - 1;
    }
}
```
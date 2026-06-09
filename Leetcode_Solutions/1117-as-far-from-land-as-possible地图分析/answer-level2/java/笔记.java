### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        Queue<int[]> queue = new ArrayDeque<>();
        int i, j;
         //将陆地加入，加入队列
        for (i = 0; i < grid.length; i++) {
            for (j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    queue.offer(new int[]{i, j});
                }
            }
        }
         

        boolean hasocean = false; //记录是否有没有海洋
        int[] point = null; 
        while (!queue.isEmpty()) {
            point = queue.poll(); 
            for (i = 0; i < 4; i++) {
                int newx = point[0] + dx[i];
                int newy = point[1] + dy[i];
                if (newx < 0 || newy < 0 || newx >= grid.length || newy >= grid[newx].length
                  || grid[newx][newy] != 0) //数组越界问题
                    continue;
                grid[newx][newy] = grid[point[0]][point[1]] + 1; //每走一步就+1
                hasocean=true;
                queue.offer(new int[]{newx, newy}); //将海洋坐标加入队列
            }
        }

        // 没有陆地或者没有海洋，返回-1。
        if (point == null || !hasocean) {
            return -1;
        }

        // 返回最后一次遍历到的海洋的距离。
        return grid[point[0]][point[1]] - 1;

    }
}
```
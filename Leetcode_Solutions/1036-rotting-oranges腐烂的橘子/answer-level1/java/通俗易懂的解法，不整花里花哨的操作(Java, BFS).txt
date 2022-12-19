```java
class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid == null) return -1;
        boolean good = false; //这个变量判断0时刻是否还有新鲜的橘子
        Deque<int[]> dq = new LinkedList<>(); 
        int n = grid.length, m = grid[0].length;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                //0时刻腐烂的橘子入队
                if(grid[i][j] == 2) dq.addLast(new int[]{i, j});
                if(grid[i][j] == 1) good = true;
            }
        if(!good) return 0;
        int time = -1;
        while(dq.size() != 0){
            time++;
            int size = dq.size();
            //  这个时刻所有腐烂的橘子都污染四周后，才开始下一分钟
            for(int i = 0; i < size; i++){
                int[] orange = dq.pollFirst();
                int x = orange[0], y = orange[1];
                // 判断四周的算法用官方的思路更加简洁，我这里写的很差
                if(x - 1 >= 0 && grid[x-1][y] == 1){
                    dq.addLast(new int[]{x - 1, y});
                    grid[x-1][y] = 2;
                }
                if(x + 1 < n && grid[x+1][y] == 1){
                    dq.addLast(new int[]{x + 1, y});
                    grid[x+1][y] = 2;
                }
                if(y - 1 >= 0 && grid[x][y-1] == 1){
                    dq.addLast(new int[]{x, y - 1});
                    grid[x][y-1] = 2;
                }
                if(y + 1 < m && grid[x][y+1] == 1){
                    dq.addLast(new int[]{x, y + 1});
                    grid[x][y+1] = 2;
                }             
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1) return -1;
        return time;
    }
}
```

# 时间复杂度：O(NM)
- 所有腐烂橘子都经过了**一次**队列
# 空间复杂度：O(NM)
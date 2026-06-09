### 思路一:  

**最常规的思路：**  
找出每一个海洋到陆地的最短距离取其最大值 用时774ms
```java
class Solution {
    //最大的距离
    private int dis = -1;
    //四个方向
    private static final int[][]  dirs= {{1, 0},{0, 1},{0, -1},{-1, 0}};
    public int maxDistance(int[][] grid) {
        int nSize = grid.length;
        for(int r = 0; r < nSize; r++){
            for(int c = 0; c < nSize; c++){
                if(grid[r][c] == 0){
                    //找出所有的海洋到陆地的最短距离
                    bfs(grid, r, c, nSize);
                }
            }
        }
        return dis;
    }
    //常规bfs，找到第一个陆地就返回
    void bfs(int[][] grid, int r, int c, int nSize){
        Queue<int[]> queue = new LinkedList<>();
        int[][] visit = new int[nSize][nSize];
        queue.offer(new int[]{r, c});
        while(!queue.isEmpty()){
            int[] cd = queue.poll();
            for (int[] dir : dirs) {
                int newR = cd[0] + dir[0], newC = cd[1] + dir[1];
                if(newR >= nSize || newR < 0 || newC >= nSize || newC < 0) continue;
                if(visit[newR][newC] == 1) continue;
                visit[newR][newC] = 1;
                if(grid[newR][newC] == 1){
                    dis = Math.max(dis, Math.abs(newR - r) + Math.abs(newC - c));
                    return;
                }
                queue.offer(new int[]{newR, newC});
            }
        }
    }
}
```

### 思路二：  

**优化思路：**  
- 将思路转变为从所有陆地出发，找到最远的海洋。
- 这样做的好处就是就可以一次性将陆地全部入队列，可以实现同时搜索

```java
class Solution {
    //最大的距离
    public int maxDistance(int[][] grid) {
        int nSize = grid.length, dis = -1, qSize = 0;
        int[][]  dirs= {{1, 0},{0, 1},{0, -1},{-1, 0}};
        Queue<int[]> queue = new LinkedList<>();
        for(int r = 0; r < nSize; r++){
            for(int c = 0; c < nSize; c++){
                if(grid[r][c] == 1){
                    //将所有的陆地入队列
                    queue.offer(new int[]{r, c});
                }
            }
        }
        //如果全为陆地，则返回-1
        if(queue.size() / nSize == nSize) return -1;
        while(!queue.isEmpty()){
            //用dis来记录bfs深度，最后得到的深度就是陆地到最远海洋的距离
            dis++;
            qSize = queue.size();
            while(qSize-- > 0){
                int[] cd = queue.poll();
                for (int[] dir : dirs) {
                    int newR = cd[0] + dir[0], newC = cd[1] + dir[1];
                    if(newR >= nSize || newR < 0 || newC >= nSize || newC < 0) continue;
                    if(grid[newR][newC] == 1) continue;
                    grid[newR][newC] = 1;
                    //当且仅当该区域是海洋的时候才会入队列
                    queue.offer(new int[]{newR, newC});
                }
            }
        }
        return dis;
    }
}
```
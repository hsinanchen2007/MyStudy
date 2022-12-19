idea来自于花花酱的视频 https://www.bilibili.com/video/av79362682/ ， 提供下JAVA版本
```
// 1293 有障碍物的最短路径，拥有K个消除权力的
    public int shortestPath(int[][] grid, int k) {
        int[] dirs = new int[]{0, -1, 0, 1, 0};
        int m = grid.length, n = grid[0].length;
        int[] seen = new int[m * n];
        Arrays.fill(seen, Integer.MAX_VALUE);
        LinkedList<Tuple> q = new LinkedList<>();
        int ans = 0;
        q.add(new Tuple(0, 0, 0));
        seen[0] = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                Tuple t = q.poll();
                int x = t.x, y = t.y, z = t.z;
                if (x == m - 1 && y == n - 1) return ans;
                for (int j = 0; j < 4; j++) {
                    int nx = x + dirs[j];
                    int ny = y + dirs[j + 1];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    int ob = z + grid[x][y];
                    // 剪枝，视频时间线：  7:30开始  
//关键点： 当前第I层，路径step相等下，拥有的节点   已经移除的obstacle更少，那么它拥有更好的潜力（因为它移除obstacle的机会更多），所以需要push这个选节点进去
                    if (ob >= seen[nx * n + ny] || ob > k) continue;
                    seen[nx * n + ny] = ob;
                    q.add(new Tuple(nx, ny, ob));
                }
            }
            ans++;
        }
        return -1;
    }

    public class Tuple {
        public int  x,y,z;
        public Tuple(int x,int y,int z){
        this.x=x;this.y=y;this.z=z;
    }
}

```


# 解题思路：

如果只有箱子，那么这道题就是普通的BFS，因为只要是地板，箱子就能走。从当前位置一圈一圈往外扩，直到移动到目标位置。
但这道题的箱子不能随便移动，如果箱子想往某个方向移动，前提是 **人要能到箱子的反方向**。
例如箱子向往左移动，前提是人能移动到到箱子的右边。
也就是说，在推完一次箱子后，人从当前位置进行搜索，看能否到箱子的另外3个方向，如果能，并且则到这些能到的位置进行下一次推箱子操作

# 算法流程：

1.找到人能推箱子的初始状态：
从题目给的初始状态开始对人进行bfs，看能到箱子4个相邻位置的哪些位置，找到加入队列
2.从队列中出队，以这些位置的人的位置为起点，继续看能到箱子另外3个相邻位置的哪些位置，找到后加入队列，并进行移动，然后移动次数+1放回队列
3.知道当前箱子就在目标位置，或者队列为空。

# 代码：


```
public class Lt1263 {

    public int minPushBox(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        /**
         * 放入队列中的数据结构：
         * 人在箱子的相邻位置
         * arr[0]: 人的横坐标
         * arr[1]: 人的纵坐标
         * arr[2]: 箱子的横坐标
         * arr[3]: 箱子的纵坐标
         * arr[4]: 当前已经推了多少次
         */
        Queue<int[]> queue = new LinkedList<>();

        // 箱子初始坐标
        int bx = 0;
        int by = 0;
        // 人初始坐标
        int sx = 0;
        int sy = 0;
        // 目标位置
        int tx = 0;
        int ty = 0;

        for (int i = 0;i<m;i++){
            for (int j = 0;j<n;j++){
                if(grid[i][j] == 'B'){
                    bx = i;
                    by = j;
                }
                if(grid[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j] == 'T'){
                    tx = i;
                    ty = j;
                }
            }
        }

        int[][] turns = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
        Set<Integer> set = new HashSet<>();
        boolean[][][][] visited = new boolean[m][n][m][n];

        // 找到初始状态下，人能到箱子的哪些相邻位置上，加入队列
        for (int i = 0;i<turns.length;i++){
            int cansx = bx + turns[i][0];
            int cansy = by + turns[i][1];
            if(isValidInGrid(m,n,cansx,cansy) && grid[cansx][cansy] != '#'
                    // 能否从sx,sy位置到达cansy,cansy位置
                    && canArrive(sx,sy,cansx,cansy,grid,turns,m,n,set)){
                queue.offer(new int[]{cansx,cansy,bx,by,0});
                visited[cansx][cansy][bx][by] = true;
            }
        }

        grid[bx][by] = '.';
        while (!queue.isEmpty()){
            // 从上次推完后的位置，开始尝试另外3种可能性
            int[] poll = queue.poll();
            // 上一次人在的位置
            int lastsx = poll[0];
            int lastsy = poll[1];
            // 上一次箱子在的位置
            int lastbx = poll[2];
            int lastby = poll[3];

            // 找到目标位置，返回结果
            if(lastbx == tx && lastby == ty){
                return poll[4];
            }
            int curMoveSize = poll[4];
            grid[lastbx][lastby] = 'B';

            // 依次看人能否到箱子的另外3个相邻位置，乳沟能到，就推一次，
            for (int i = 0;i<turns.length;i++){
                int newbx = lastbx + turns[i][0];
                int newby = lastby + turns[i][1];
                int beforesx = lastbx - turns[i][0];
                int beforesy = lastby - turns[i][1];
                if(isValidInGrid(m,n,newbx,newby) &&
                  isValidInGrid(m,n,beforesx,beforesy) &&
                    grid[newbx][newby] != '#' &&
                        grid[beforesx][beforesy] != 'B' &&
                        !visited[lastbx][lastby][newbx][newby] &&
                    canArrive(lastsx,lastsy,beforesx,beforesy,grid,turns,m,n,set)){
                    visited[lastbx][lastby][newbx][newby] = true;
                    // 如果没有问题，将退完后的位置放进队列
                    queue.offer(new int[]{lastbx,lastby,newbx,newby,curMoveSize + 1});
                }
            }
            grid[lastbx][lastby] = '.';
        }
        return -1;
    }

    /**
     *  人能否从sx,sy位置到达cansy,cansy位置，使用bfs遍历
     */
    private boolean canArrive(int sx, int sy, int cansx, int cansy, char[][] grid,int[][] turns,int m,int n,Set<Integer> set) {
        set.clear();
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{sx,sy});
        set.add(sx * n + sy);
        while (!queue.isEmpty()){
            int[] poll = queue.poll();
            if(poll[0] == cansx && poll[1] == cansy){
                return true;
            }
            for (int i = 0;i<turns.length;i++){
                int newx = poll[0] + turns[i][0];
                int newy = poll[1] + turns[i][1];
                if(isValidInGrid(m,n,newx,newy)
                        && grid[newx][newy] != '#'
                        && grid[newx][newy] != 'B'
                        && !set.contains(newx * n + newy)){
                    queue.offer(new int[]{newx,newy});
                    set.add(newx * n + newy);
                }
            }
        }
        return false;

    }

    /**
     * 校验坐标是否合法
     */
    private boolean isValidInGrid(int m,int n,int x,int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}
```

# 复杂度计算：

时间复杂度：O(m^2 * n^2 )

最多有m*n*4个位置，对每个位置可能进行一次bfs：每次bfs消耗 m*n

空间复杂的：O(mn)

队列最多offer 4*m*n个元素，visited数组可以优化成用对象表示，重写equals



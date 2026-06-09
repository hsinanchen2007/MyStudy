// ### 解法 BFS

// ```java
private static int[][] ds = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private Queue<int[]> queue;
    private int n, m;

    public int orangesRotting(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    queue.add(new int[]{i, j}); // 第0天就腐烂的
        }
        while (!queue.isEmpty()) {
            int[] pos = queue.remove();
            newRot(grid, pos);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1)
                    return -1;
                res = Math.max(res, grid[i][j]);
            }
        }
        return res >= 2 ? res - 2 : 0; // 避免格子中没有放橘子的情况
    }

    private void newRot(int[][] grid, int[] pos) {
        int x = pos[0], y = pos[1];
        for(int[] d : ds){
            int newX = x + d[0];
            int newY = y + d[1];
            if(isIn(newX, newY) && grid[newX][newY] == 1){
                grid[newX][newY] = grid[x][y] + 1;
                queue.add(new int[]{newX, newY});
            }
        }
    }

    private boolean isIn(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
// ```

// 思路分析：

// * 首先，腐烂橘子会感染上下左右四个方向的橘子，如果我们将腐烂橘子看成一个结点，那么其上下左右四个方向的橘子腐烂后也成为一个结点，他们都是相连接的。所以腐烂橘子其实构成了一个图，这个图中有一个或者多个连通子图。
// * 由于橘子一分钟可以将上下左右的橘子腐烂，这个过程就像无向图中的搜索过程，要求橘子的腐烂完全的最短分钟数，就等价于在无向图中找到达到各个结点的最短路径中的最大值。所以明确之后就很简单，就是一个BFS，只不过有这里有多个连通子图。
// * 就像回溯算法题解中很常见的二维平面的搜索。实例变量`int[][] ds`表示上下左右移动的坐标变化量，并且用`private int n, m;`分别表示行列数。且写一个防止数组索引越界的判断函数` private boolean isIn(int x, int y)`。
// * 接下来，完成我们BFS函数的设计。
//     * 需要一个保留结点的队列`private Queue<int[]> queue;`
//     * 由于连通子图的存在，9-13行将所有初始时候腐烂的橘子`grid[i][j] == 2`的坐标放入队列中。
//     * 对于某个点的搜索，使用函数`newRot(int[][] grid, int[] pos)`，第二个参数表示该点的坐标，将该点上下左右四个点的坐标算出，保证不越界的情况下`isIn(newX, newY)`，如果相邻四点有新鲜橘子`grid[newX][newY] == 1`。将该橘子感染时间设置为上一个橘子感染时间加1。然后放入队列，准备用它再去感染别的橘子（用它接着进行广度优先遍历）
//     * 感染时间直接使用`grid[][]`来记录，规定初始时候感染的橘子为2这个时刻。
//     * 14-17行，腐烂橘子队列非空时取出一个腐烂的橘子，将其周围感染，通过`newRot`函数只会感染相邻的。
// * 搜索完成后，再一次遍历，如果有发现未感染的橘子`grid[i][j] == 1`，依照题意返回-1。否则记录最晚感染的橘子在第几分钟被感染。
// * 当然最后还需要注意，有一种情况，初始时压根就没有新鲜橘子，这个时候要返回的是0，所以最后返回值还需要一个判断`return res >= 2 ? res - 2 : 0;`

// 运行结果：

// * 执行用时 :3 ms, 在所有 Java 提交中击败了71.71%的用户
// * 内存消耗 :38.6 MB, 在所有 Java 提交中击败了52.94%的用户

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖
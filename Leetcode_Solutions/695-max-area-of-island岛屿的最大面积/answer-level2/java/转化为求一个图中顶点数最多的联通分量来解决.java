```
import java.util.HashSet;

/**
 * 解决思路:
 *    1. 使用图相关算法解决该问题
 *    2. 思考如何建图
 *       - 把二维数组中每一个数当成是图中的一个顶点
 *       - 为每一个顶点创建一个HashSet(邻接表), HashSet中存储与该顶点相邻的边
 *    3. 该问题就转化为了求图中顶点数最多的联通分量
 *
 *  两个注意点:
 *    1. 二维数组跟一维数组之间互相转换 (C为二维数组的列数):
 *       2->1: (x, y) --> v = x * C + y
 *      1->2:  v --> x = v / C; y = v % C
 *
 *    2. 如何表示某个点(x, y)的四个方向
 *      定义一个方向数组 dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
 *      for (int d = 0; d < 4; d ++) {
 *          int nextx = x + dirs[d][0];
 *          int nexty = y + dirs[d][1];
 *      }
 *      (nextx, nexty) 即分别为上右下左四个方向在grid二维数组中的行列数
 *
 */
public class Solution_695 {

    private int R;
    private int C;
    private HashSet<Integer>[] G;
    private int[][] grid;
    private boolean[] visited;
    private int[][] dirs = {
            {-1, 0}, {0, 1},
            {1, 0}, {0, -1}
    };

    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null) return 0;
        R = grid.length;
        if (R == 0) return 0;
        C = grid[0].length;
        if (C == 0) return 0;

        this.grid = grid;

        G = constructGraph();
        visited = new boolean[G.length];

        int res = 0;
        for ( int v = 0; v < G.length; v ++ ) {
            int x = v / C, y = v % C;
            if (grid[x][y] == 1 && !visited[v]) {
                res = Math.max(res, dfs(v));
            }
        }

        return res;
    }

    private int dfs(int v) {

        visited[v] = true;

        int res = 1;
        for ( int w : G[v] ) {
            if (!visited[w])
                res += dfs(w);
        }

        return res;
    }

    private HashSet<Integer>[] constructGraph() {
        HashSet<Integer>[] res = new HashSet[R*C];
        for ( int i = 0; i < res.length; i ++ ) {
            res[i] = new HashSet<>();
        }

        for ( int v = 0; v < res.length; v ++ ) {
            int x = v / C, y = v % C;
            if (grid[x][y] == 1) {
                for (int d = 0; d < 4; d ++) {
                    int nextx = x + dirs[d][0];
                    int nexty = y + dirs[d][1];
                    if ( inArea(nextx, nexty) && grid[nextx][nexty] == 1 ) {
                        int next = nextx * C + nexty;
                        res[v].add(next);
                        res[next].add(v);
                    }
                }
            }
        }

        return res;
    }

    private boolean inArea(int x, int y) {
        return x >= 0 && x < R && y >= 0 && y < C ;
    }
}

```

```
import java.util.HashSet;

/**
 * 解决思路(floodfill算法):
 *    1. 使用图相关算法解决该问题
 *    2. 不使用邻接表创建图, 直接把grid当成是一张图
 *    3. 该问题就转化为了求图中顶点数最多的联通分量
 */
public class Solution {

    private int R;
    private int C;
    private int[][] grid;
    private boolean[][] visited;
    private int[][] dirs = {
            {-1, 0}, {0, 1},
            {1, 0}, {0, -1}
    };

    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null) return 0;
        R = grid.length;
        if (R == 0) return 0;
        C = grid[0].length;
        if (C == 0) return 0;

        this.grid = grid;

        visited = new boolean[R][C];

        int res = 0;
        for ( int i = 0; i < R; i ++ ) {
            for ( int j = 0; j < C; j ++ ) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    res = Math.max(res, dfs(i, j));
                }
            }
        }

        return res;
    }

    private int dfs(int x, int y) {

        visited[x][y] = true;

        int res = 1;
        for ( int d = 0; d < 4; d ++ ) {
            int nextx = x + dirs[d][0];
            int nexty = y + dirs[d][1];
            if (inArea(nextx, nexty) &&
                grid[nextx][nexty] == 1 && !visited[nextx][nexty])
                res += dfs(nextx, nexty);
        }
        return res;
    }

    private boolean inArea(int x, int y) {
        return x >= 0 && x < R && y >= 0 && y < C ;
    }
}

```


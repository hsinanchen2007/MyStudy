``` java

import java.util.Arrays;

class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        // 1构造邻接矩阵
        int[][] map = new int[N][N];
        int INF = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            Arrays.fill(map[i], INF);
        }
        for (int e[] : times) {
            map[e[0] - 1][e[1] - 1] = e[2];
            map[e[0] - 1][e[0] - 1] = 0;
            map[e[1] - 1][e[1] - 1] = 0;
        }
        // 2调用floyd算法求最短距离
        floyd(map, N, INF);
        int rst = -1;
        // 3求出邻接矩阵中k-1行的最大值
        for (int i = 0; i < N; i++) {
            if (map[K - 1][i] == INF) return -1;
            rst = Math.max(rst, map[K - 1][i]);
        }
        return rst;
    }

    void floyd(int[][] A, int N, int INF) {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (A[i][k] == INF || A[k][j] == INF || i == j) continue;
                    A[i][j] = Math.min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
        return;
    }

    public static void main(String[] args) {
        int N = 4, K = 2;
        int[][] map = new int[][]{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
        int c = new Solution().networkDelayTime(map, N, K);
        System.out.println(c);
    }
}
```
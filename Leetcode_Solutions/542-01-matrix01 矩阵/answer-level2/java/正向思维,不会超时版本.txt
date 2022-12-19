    static int[][] direction = new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    static int[][] dp;

    static int[][] matrixs;

    public static void findBFS(int x, int y) {
        // 替代堆栈
        // 0存放x 1 存放 y , 2 存放count
        ArrayDeque<int[]> deq = new ArrayDeque<int[]>();
        deq.add(new int[] {x, y, -1});
        // int[][] vist = new int[matrixs.length][matrixs[0].length];
        // vist[x][y] = 1;
        while (!deq.isEmpty()) {
            // 队列
            int[] cu = deq.pollFirst();
            if (matrixs[cu[0]][cu[1]] == 0) {
                dp[x][y] = cu[2] + 1;
                break;
            }
            // vist[cu[0]][cu[1]] = 1;

            // // 不考虑已有
            // if (dp[cu[0]][cu[1]] > 0) {
            // dp[x][y] = dp[cu[0]][cu[1]] + 1;
            // break;
            // }
            // bfs不用维护是否已经访问过,因为最终都会访问完,找到最后的
            for (int i = 0; i < direction.length; i++) {
                int xnext = cu[0] + direction[i][0];
                int ynext = cu[1] + direction[i][1];
                if (xnext >= 0 && xnext < matrixs.length && ynext >= 0
                    && ynext < matrixs[0].length /* &&vist[xnext][ynext] == 0 */ ) {
                    deq.add(new int[] {xnext, ynext, cu[2] + 1});
                }
            }

        }

    }

    public static int[][] updateMatrix(int[][] matrix) {
        // 可以共享,存放距离,如果为>0 访问过了
        dp = new int[matrix.length][matrix[0].length];
        matrixs = matrix;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 1) {
                    findBFS(i, j);
                }
            }
        }

        return dp;

    }
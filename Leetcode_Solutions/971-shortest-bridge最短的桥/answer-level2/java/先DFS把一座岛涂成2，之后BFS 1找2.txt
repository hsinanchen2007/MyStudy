```
public class ShortestBridge {
    private static final int[][] DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    private static final int SECOND_BRIDGE = 2;

    private static final int DIRECTIONS_SIZE = 4;

    public int shortestBridge(int[][] A) {
        tagSecondBridge(A);

        int nr = A.length;
        int nc = A[0].length;
        Queue<Node> queue = new LinkedList<>();
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (A[i][j] == 1) {
                    queue.offer(new Node(i, j, 0));
                    A[i][j] = -1;
                }
            }
        }
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            for (int i = 0; i < DIRECTIONS_SIZE; i++) {
                int curR = node.r + DIRECTIONS[i][0];
                int curC = node.c + DIRECTIONS[i][1];
                if (curC < 0 || curC >= nc || curR < 0 || curR >= nr || A[curR][curC] == -1) {
                    continue;
                }
                if (A[curR][curC] == SECOND_BRIDGE) {
                    return node.step;
                }
                A[curR][curC] = -1;// 关键一行，缺少运行正确不过超过时间限制
                queue.offer(new Node(curR, curC, node.step + 1));
            }
        }
        return -1;
    }

    class Node {
        int r;

        int c;

        int step;

        Node(int r, int c, int step) {
            this.r = r;
            this.c = c;
            this.step = step;
        }
    }

    private void tagSecondBridge(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j);
                    return;
                }
            }
        }
    }

    private void dfs(int[][] A, int r, int c) {
        if (r < 0 || r >= A.length || c < 0 || c >= A[0].length || A[r][c] != 1) {
            return;
        }
        A[r][c] = SECOND_BRIDGE;
        for (int i = 0; i < DIRECTIONS_SIZE; i++) {
            dfs(A, r + DIRECTIONS[i][0], c + DIRECTIONS[i][1]);
        }
    }
}
```

### 解题思路
用广度优先算法将与四个边上的O连通的O变为Y，然后剩下的O即为被包围的，变为X即可，最后再遍历一遍把Y变回O

### 代码

```java
class Solution {
    public void solve(char[][] board) {
        int M = board.length;
        if (M == 0) return;
        int N = board[0].length;

        Queue<int[]> queue = new LinkedList<>();

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if ((i > 0 && i < M - 1) && (j > 0 && j < N - 1))
                    continue;
                if (board[i][j] == 'O'){
                    queue.add(new int[]{i, j});
                    board[i][j] = 'Y';
                }
            }
        }

        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 0; i < n; i++){
                int[] cur = queue.poll();
                int r = cur[0];
                int c = cur[1];

                if (r > 0 && board[r - 1][c] == 'O') {
                    board[r - 1][c] = 'Y';
                    queue.add(new int[]{r - 1,c});
                }

                if (r + 1 < M && board[r + 1][c] == 'O') {
                    board[r + 1][c] = 'Y';
                    queue.add(new int[]{r + 1,c});
                }

                if (c > 0 && board[r][c - 1] == 'O') {
                    board[r][c - 1] = 'Y';
                    queue.add(new int[]{r,c - 1});
                }

                if (c + 1 < N && board[r][c + 1] == 'O') {
                    board[r][c + 1] = 'Y';
                    queue.add(new int[]{r,c + 1});
                }
            }  
        }

        for (int i = 1; i < M - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }
}
```
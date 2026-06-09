执行用时 :7 ms, 在所有 Java 提交中击败了71.88%的用户
内存消耗 :41.7 MB, 在所有 Java 提交中击败了20.16%的用户
```
public class lt79 {
    public static boolean isEX;
    public static int[][] book;

    public boolean exist(char[][] board, String word) {
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int n = board.length;
        int m = board[0].length;
        book = new int[n][m];
        isEX = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!isEX) {
                    if (board[i][j] == word.charAt(0)) {
                        book[i][j] = 1;
                        exist(board, i, j, word, dx, dy, 1);
                        book[i][j] = 0;
                    }
                } else {
                    return true;
                }

            }
        }
        return isEX;
    }

    private void exist(char[][] board, int i, int j, String word, int[] dx, int[] dy, int dfslen) {
        if (word.charAt(dfslen - 1) == (board[i][j])) {
            if (dfslen == word.length()) {
                isEX = true;
            } else {
                for (int k = 0; k < 4; k++) {
                    int nexati = i + dx[k];
                    int nexatj = j + dy[k];
                    if (nexati >= 0 && nexati <= board.length - 1 && nexatj >= 0 && nexatj <= board[0].length - 1 && book[nexati][nexatj] == 0 && !isEX) {
                        book[nexati][nexatj] = 1;
                        exist(board, nexati, nexatj, word, dx, dy, dfslen + 1);
                        book[nexati][nexatj] = 0;
                    }
                }

            }

        }
    }
}

```
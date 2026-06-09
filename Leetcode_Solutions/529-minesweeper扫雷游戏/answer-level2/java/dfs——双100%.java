思路：从点击点开始，dfs遍历周围的八个点（四周）。每遍历到一个点，判断是否为数字或者地雷（此点结束），否则改为空白'B'。
此时，修改此点的最终数字（周围地雷数）。
1.如果此点为数字：此点结束。
2.如果此点为空白'B'：dfs此点
```
class Solution {
    private int[] x = new int[] { 1, 0, -1, 0, 1, 1, -1, -1 };
    private int[] y = new int[] { 0, 1, 0, -1, 1, -1, -1, 1 };
    private char[][] board;

    public char[][] updateBoard(char[][] board, int[] click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        } else if (board[click[0]][click[1]] == 'E') {
            board[click[0]][click[1]] = 'B';
        }
        this.board = board;
        dfs(click[0], click[1]);
        return board;
    }

    private void dfs(int i, int j) {
        nearM(i, j);
        if (board[i][j] != 'B')
            return;
        for (int g = 0; g < 8; g++) {
            if (i + x[g] < board.length && i + x[g] > -1 && j + y[g] < board[0].length && j + y[g] > -1
                    && board[i + x[g]][j + y[g]] == 'E') {
                board[i + x[g]][j + y[g]] = 'B';
                dfs(i + x[g], j + y[g]);
            }
        }
    }

    private void nearM(int i, int j) {
        for (int g = 0; g < 8; g++) {
            if (i + x[g] < board.length && i + x[g] > -1 && j + y[g] < board[0].length && j + y[g] > -1
                    && board[i + x[g]][j + y[g]] == 'M') {
                board[i][j] = board[i][j] == 'B' ? '1' : (char) (board[i][j] + 1);
            }
        }
    }
}
```

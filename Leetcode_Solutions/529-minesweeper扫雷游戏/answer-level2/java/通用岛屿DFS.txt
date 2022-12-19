```
class Solution {
    private int[][] dirArr = new int[][]{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

    public char[][] updateBoard(char[][] board, int[] click) {
        int row = click[0], col = click[1];
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }
        dfs(board, row, col);
        return board;
    }

    private void dfs(char[][] board, int r, int c) {
        if (inArea(board, r, c) && board[r][c] == 'E') {
            int count = 0;
            for (int[] dir : dirArr) {
                int row = r + dir[0], col = c + dir[1];
                if (inArea(board, row, col) && (board[row][col] == 'M' || board[row][col] == 'X')) {
                    count++;
                }
            }
            if (count > 0) {
                board[r][c] = (char) (count + '0');
                return;
            }
            board[r][c] = 'B';
            for (int[] dir : dirArr) {
                int row = r + dir[0], col = c + dir[1];
                if (inArea(board, row, col) && board[row][col] == 'E') {
                    dfs(board, row, col);
                }
            }
        }
    }

    private boolean inArea(char[][] board, int r, int c) {
        return r >= 0 && r < board.length && c >= 0 && c < board[0].length;
    }
}
```

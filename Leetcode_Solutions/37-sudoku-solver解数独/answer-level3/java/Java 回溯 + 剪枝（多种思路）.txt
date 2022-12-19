1、思路一，实时校验，校验时循环行、列、块判重
```java
class Solution {
    public void solveSudoku(char[][] board) {
        if (board == null || board.length != 9 || board[0].length != 9) return;
        solveSudokuHelper(board, 0);
    }

    boolean solveSudokuHelper(char[][] board, int n) {
        if (n == 81) return true;
        int i = n / 9, j = n % 9;
        if (board[i][j] != '.') return solveSudokuHelper(board, n + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (!isValidSudoku(board, i, j, c)) continue;
            board[i][j] = c;
            if (solveSudokuHelper(board, n + 1)) return true;
        }
        board[i][j] = '.';
        return false;
    }

    boolean isValidSudoku(char[][] board, int i, int j, char val) {
        for (int x = 0; x < 9; x++) {
            if (board[i][x] == val || board[x][j] == val || board[(i / 3) * 3 + x / 3][(j / 3) * 3 + x % 3] == val)
                return false;
        }
        return true;
    }
}
```

2、思路二，提前预设行、列、块，避免校验时循环（效率更高）

```java
class Solution {
    public void solveSudoku(char[][] board) {
        if (board == null || board.length != 9 || board[0].length != 9) return;
        boolean[][] row = new boolean[9][9];
        boolean[][] col = new boolean[9][9];
        boolean[][] box = new boolean[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1', k = (i / 3) * 3 + j / 3;
                row[i][num] = col[j][num] = box[k][num] = true;
            }
        }
        solveSudokuHelper(board, 0, row, col, box);
    }

    boolean solveSudokuHelper(char[][] board, int n, boolean[][] row, boolean[][] col, boolean[][] box) {
        if (n == 81) return true;
        int i = n / 9, j = n % 9;
        if (board[i][j] != '.') return solveSudokuHelper(board, n + 1, row, col, box);

        int k = (i / 3) * 3 + j / 3;
        for (int num = 0; num < 9; num++) {
            if (row[i][num] || col[j][num] || box[k][num]) continue;
            board[i][j] = (char) ('1' + num);
            row[i][num] = col[j][num] = box[k][num] = true;
            if (solveSudokuHelper(board, n + 1, row, col, box)) return true;
            row[i][num] = col[j][num] = box[k][num] = false;
        }
        board[i][j] = '.';
        return false;
    }
}
```

3、思路三，通过位运算快速判重
待更新
```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[] used = new boolean[9]; // 标志字符是否已存在
        for (int i = 0; i < 9; i++) {
            Arrays.fill(used, false);
            for (int j = 0; j < 9; j++) { // 行
                if (!check(board[i][j], used)) {
                    return false;
                }
            }
            Arrays.fill(used, false);
            for (int j = 0; j < 9; j++) { // 列
                if (!check(board[j][i], used)) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Arrays.fill(used, false);  // 3*3子矩阵
                for (int m = 3 * i; m < 3 * i + 3; m++) {
                    for (int n = 3 * j; n < 3 * j + 3; n++) {
                        if (!check(board[m][n], used)) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    // 判断条件
    public boolean check(char ch, boolean[] used) {
        if (ch == '.') {
            return true;
        }
        if (used[ch - '1']) {
            return false;
        }

        used[ch - '1'] = true;
        return true;
    }
}
```

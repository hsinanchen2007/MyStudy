```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            //1. 首先遍历行，检查每行元素是否有错误
            HashSet<Character> set_row = new HashSet<>();
            for (char c : board[i]) {
                if (c == '.') {
                    continue;
                }
                if (set_row.contains(c)) {
                    return false;
                }
                set_row.add(c);
            }

            //2. 遍历列，检查每列的元素是否正确
            HashSet<Character> set_col = new HashSet<>();
            for (int j = 0; j < board.length; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (set_col.contains(board[j][i])) {
                    return false;
                }
                set_col.add(board[j][i]);
            }

            //3.遍历小方格
            HashSet<Character> set_ant = new HashSet<>();
            int x = (i / 3) * 3;
            int y = (i % 3) * 3;
            for (int k = x; k < x + 3; k++) {
                for (int l = y; l < y + 3; l++) {
                    char ch = board[k][l];
                    if (ch == '.') {
                        continue;
                    }
                    if (set_ant.contains(ch)) {
                        return false;
                    }
                    set_ant.add(ch);
                }
            }
        }
        return true;
    }
}

```
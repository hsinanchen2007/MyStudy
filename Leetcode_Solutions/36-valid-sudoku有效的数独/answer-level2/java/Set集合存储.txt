
**思路: 利用row、col、block分别存储各行、各列、各块信息, 一边遍历一边比较重复**
```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<Character>[] row = (Set<Character>[])new Set[board.length];
        Set<Character>[] col = (Set<Character>[])new Set[board.length];
        Set<Character>[] block = (Set<Character>[])new Set[board.length];
        for (int i = 0; i < board.length; ++i) {
            row[i] = new HashSet<>();
            col[i] = new HashSet<>();
            block[i] = new HashSet<>();
        }
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board.length; ++j) {
                if (board[i][j] != '.') {
                    if (row[i].contains(board[i][j]) || col[j].contains(board[i][j]) || 
                        block[i / 3 * 3 + j / 3].contains(board[i][j])) {
                            return false;
                    } else {
                        row[i].add(board[i][j]);
                        col[j].add(board[i][j]);
                        block[i / 3 * 3 + j / 3].add(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
}
```

**思路: 依次对每行进行遍历, 对每一个空位尝试填入1-9, 若1-9均无效则无解, 若便利完9x9表格则成果**
```
class Solution {
        public void solveSudoku(char[][] board) {
        Set<Character>[] rowSet = (Set<Character>[])new HashSet[board.length];
        Set<Character>[] colSet = (Set<Character>[]) new HashSet[board.length];
        Set<Character>[] blockSet = (Set<Character>[]) new HashSet[board.length];
        for (int i = 0; i < board.length; ++i) {
            rowSet[i] = new HashSet<>();
            colSet[i] = new HashSet<>();
            blockSet[i] = new HashSet<>();
        }
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] != '.') {
                    rowSet[i].add(board[i][j]);
                    colSet[j].add(board[i][j]);
                    blockSet[i / 3 * 3 + j / 3].add(board[i][j]);
                }
            }
        }
        dfs(board, rowSet, colSet, blockSet);
    }

    private boolean dfs(char[][] board, Set<Character>[] rowSet, Set<Character>[] colSet, Set<Character>[] blockSet) {
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; ++k) {
                        if (!rowSet[i].contains(k) && !colSet[j].contains(k) && !blockSet[i / 3 * 3 + j / 3].contains(k)) {
                            board[i][j] = k;
                            rowSet[i].add(k);colSet[j].add(k);blockSet[i / 3 * 3 + j / 3].add(k);
                            if (dfs(board, rowSet, colSet, blockSet)) return true;
                            board[i][j] = '.';
                            rowSet[i].remove(k);colSet[j].remove(k);blockSet[i / 3 * 3 + j / 3].remove(k);
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

}
```
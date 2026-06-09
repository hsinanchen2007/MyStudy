和大部分的题解类似，只不过加了一个原地算法，避免使用 boolean[][] 来保存状态，空间复杂度超越 100% 用户
```
class Solution {
    private boolean res = false;
    private int rows;
    private int cols;

    public boolean exist(char[][] board, String word) {
        rows = board.length;
        cols = board[0].length;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (board[i][j] == word.charAt(0)) {
                    dfs(board, i, j, word, 0);
                }
            }
        }
        return res;
    }
    
    public void dfs(char[][] board, int row, int col, String word, int index) {
        if(row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }

        if(board[row][col] == '0' || res || index >= word.length()) {
            return;
        }
        
        if(board[row][col] == word.charAt(index)) {
            if(index == word.length() - 1) {
                res = true;
                return;
            } 
            char tmp = board[row][col];
            board[row][col] = '0';
            dfs(board, row - 1, col, word, index + 1);
            dfs(board, row + 1, col, word, index + 1);
            dfs(board, row, col - 1, word, index + 1);
            dfs(board, row, col + 1, word, index + 1);
            board[row][col] = tmp;
        }
    }
}
```

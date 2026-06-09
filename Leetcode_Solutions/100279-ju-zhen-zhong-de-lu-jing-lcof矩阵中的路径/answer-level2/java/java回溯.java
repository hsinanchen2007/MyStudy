```
class Solution {
     public boolean exist(char[][] board, String word) {
        if(word.length() == 0 || board.length == 0) return false;
        int length = board.length;
        int width = board[0].length;
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < width; j++) {
                if(board[i][j] == word.charAt(0)) {
                    if(word.length() == 1) return true;
                    if (dfs(board, i, j, length, width, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, int i, int j, int length, int width, String word, int idx) {
        if(idx == word.length()) return true;
        if(board[i][j] != word.charAt(idx) || board[i][j] == '/') return false;
        char c = board[i][j];
        board[i][j] = '/';
        if(i + 1 < length) {
            if (dfs(board, i + 1, j, length, width, word, idx + 1)) {
                return true;
            }
        }
        if(i - 1 >= 0) {
            if(dfs(board, i -+ 1, j, length, width, word, idx + 1)) {
                return true;
            }
        }
        if(j - 1 >= 0) {
            if(dfs(board, i, j - 1, length, width, word, idx + 1)) {
                return true;
            }
        }
        if(j + 1 < width) {
            if(dfs(board, i, j + 1, length, width, word, idx + 1)) {
                return true;
            }
        }
        board[i][j] = c;
        return false;
    }
}
```

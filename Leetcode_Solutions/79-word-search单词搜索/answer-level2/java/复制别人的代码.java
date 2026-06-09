### 解题思路
这题需要好好看看

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        //回溯算法
        boolean[][] visited = new boolean[board.length][board[0].length];
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board[0].length; j++) {
                    if (word.charAt(0) == board[i][j] && backtrack(i, j, 0, word, visited, board)) return true;
                }
            }
            return false;

        }

        private boolean backtrack(int i, int j, int idx, String word, boolean[][] visited, char[][] board) {
            if (idx == word.length()) return true;
            if (i >= board.length || i < 0 || j >= board[0].length || j < 0 || board[i][j] != word.charAt(idx) || visited[i][j])
                return false;
            visited[i][j] = true;
            if (backtrack(i + 1, j, idx + 1, word, visited, board) || backtrack(i - 1, j, idx + 1, word, visited, board) || backtrack(i, j + 1, idx + 1, word, visited, board) || backtrack(i, j - 1, idx + 1, word, visited, board))
                return true;
            visited[i][j] = false; // 回溯
            return false;
        }
}
```
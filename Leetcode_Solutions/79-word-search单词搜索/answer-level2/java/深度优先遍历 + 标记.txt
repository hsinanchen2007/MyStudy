### 解题思路
深度优先遍历 + 标记

### 代码

```java
class Solution {
    
    public boolean exist(char[][] board, String word) {
        
        int rows = board.length, cols = board[0].length;
        // true代表被访问过
        boolean[][] trance = new boolean[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word.charAt(0)) {
                    boolean res = exist(board, i, j, trance, word, 0);
                    if (res) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    // 从board[i][j]位置开始dfs寻找word[k, len-1]
    public boolean exist(char[][] board, int i, int j, boolean[][] trance, String word, int k) {
        
        int rows = board.length, cols = board[0].length;
        
        if (k >= word.length()) {
            return true;
        }
        
        if (i < 0 || i >= rows 
            || j < 0 || j >= cols 
            || trance[i][j]
            || board[i][j] != word.charAt(k)) {
            return false;
        }
        
        trance[i][j] = true;
        boolean res = exist(board, i+1, j, trance, word, k+1)
            || exist(board, i-1, j, trance, word, k+1)
            || exist(board, i, j+1, trance, word, k+1)
            || exist(board, i, j-1, trance, word, k+1);
        
        if (res) {
            return res;
        }
        
        trance[i][j] = false;
        return false;
    }
    
    
}
```
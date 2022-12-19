### 解题思路
先比较board[i][j] 与 word第一个字符关系，然后再进行递归，执行时间4ms，击败
99.75%

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        char[] wordChars = word.toCharArray();
        int row = board.length;
        int col = board[0].length;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if( board[r][c] == wordChars[0] && dfs(board, wordChars, r, c, row, col, 0) ){
                    return true;
                }
            }
        }
        return false;

    }
    private boolean dfs(char[][] board, char[] wordChars, int r, int c, int row, int col, int k){
        if( c < 0 || r < 0 || c > col-1 || r > row-1 || board[r][c] != wordChars[k] ) return false;
        if( k == wordChars.length-1 ) return true;
        char temp = board[r][c];
        board[r][c] = '*';
        boolean flag = dfs(board, wordChars, r-1, c, row, col, k+1) || dfs(board, wordChars, r+1, c, row, col, k+1)
                    || dfs(board, wordChars, r, c-1, row, col, k+1) || dfs(board, wordChars, r, c+1, row, col, k+1);
        board[r][c] = temp;            
        return flag;
    }
}
```
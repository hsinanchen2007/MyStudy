### 解题思路
该题的思路为利用DFS来搜索从矩阵每个点为起点是否含有路径。

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        // DFS
        char[] wordChars = word.toCharArray();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (dfs(board, wordChars, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;

    }

    boolean dfs(char[][] board, char[] words, int i, int j, int index) {
        if (i >= board.length || i < 0 || j >= board[0].length || j < 0 || board[i][j] != words[index]) {
            return false;
        }
        if (index == words.length - 1) {
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '/';
        boolean res = dfs(board, words, i+1, j, index+1) 
                   || dfs(board, words, i, j+1, index+1) 
                   || dfs(board, words, i-1, j, index+1) 
                   || dfs(board, words, i, j-1, index+1);
        board[i][j] = temp;
        return res;
    }
}
```
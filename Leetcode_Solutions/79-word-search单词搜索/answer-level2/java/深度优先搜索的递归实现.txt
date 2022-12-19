### 解题思路
使用深度优先搜索的思想，利用递归实现算法。一个位置有上下左右四种方向游走，体现在dfs函数的第7行中。

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i=0; i<board.length; i++){
            for (int j=0; j<board[0].length; j++){
                if (dfs(board, i, j, word)) return true;
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, int i, int j, String word){
        // 若不符合或超出索引
        if(i<0 || i>board.length-1 || j<0 || j>board[0].length-1 || board[i][j]!=word.charAt(0)) return false;
        // 符合
        if (word.length()==0) return true;
        char tmp = board[i][j];
        board[i][j] = '0';
        boolean res = dfs(board, i+1, j, word.substring(1)) || dfs(board, i-1, j, word.substring(1)) || dfs(board, i, j+1, word.substring(1)) || dfs(board, i, j-1, word.substring(1));
        
        board[i][j] = tmp;
        return res;
    }
}
```
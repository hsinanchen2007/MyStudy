```
class Solution {
    boolean[][] mark;       // false没走过，true走过了

    public boolean exist(char[][] board, String word) {
        if(board.length == 0 || board[0].length == 0)   return false;
        mark = new boolean[board.length][board[0].length];

        // 遍历矩阵，找起始位置（要找路径，起码得从矩阵中找到一个元素==word的第一个字符吧！）
        for(int i = 0; i < board.length; i ++){
            for(int j = 0; j < board[0].length; j ++){
                if(board[i][j] == word.charAt(0)){
                    mark[i][j] = true;
                    if(helper(board, word, i, j, 1))    return true;
                    else    mark[i][j] = false;                 // 易错！！！
                }
            }
        }

        return false;
    }

    // i，j代表当前位置，index代表需要匹配的字符索引（word）
    public boolean helper(char[][] board, String word, int i, int j, int index){
        if(index == word.length())  return true;

        // 向上移动；条件是 1不出界 2还没走过 3上方元素==目标字符
        if(i - 1 >= 0 && !mark[i - 1][j] && board[i - 1][j] == word.charAt(index)){
            mark[i - 1][j] = true;
            if(helper(board, word, i - 1, j, index + 1))    return true;
            mark[i - 1][j] = false;                 // 易错！！！
        }
        // 向下移动
        if(i + 1 < board.length && !mark[i + 1][j] && board[i + 1][j] == word.charAt(index)){
            mark[i + 1][j] = true;
            if(helper(board, word, i + 1, j, index + 1))    return true;
            mark[i + 1][j] = false;                 // 易错！！！
        }
        // 向左移动
        if(j - 1 >= 0 && !mark[i][j - 1] && board[i][j - 1] == word.charAt(index)){
            mark[i][j - 1] = true;
            if(helper(board, word, i, j - 1, index + 1))    return true;
            mark[i][j - 1] = false;                 // 易错！！！
        }
        // 向右移动
        if(j + 1 < board[0].length && !mark[i][j + 1] && board[i][j + 1] == word.charAt(index)){
            mark[i][j + 1] = true;
            if(helper(board, word, i, j + 1, index + 1))    return true;
            mark[i][j + 1] = false;                 // 易错！！！
        }

        return false;
    }
}
```

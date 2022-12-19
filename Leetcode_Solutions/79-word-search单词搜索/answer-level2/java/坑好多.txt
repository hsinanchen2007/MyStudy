### 解题思路
此段代码 参考了 各位大神的，加上自己的理解，以自己的方法习惯写下来了
思路 ： 1.先循环表盘，从 word的索引0 开始 匹配 
        2.当 word[0] 匹配到之后， 分别进行上下左右 递归 进行下一个字符匹配。
        3.传入visite ，当该点匹配了设置为true，不再回头。

        4回溯：退出条件，当到word最后一位时候，返回 是否相等。

踩过几点坑，记录一下：
1.一旦 backtrack 为 true，跳出循环，不再执行。
2.重点： 当判断board中出现 索引为 index的word中的字母时，将 visited 设置为true，
        只要 上下左右任一步成功 ，则返回true，而不是 每一步都返回！！！ （我掉在这里坑里好久 太蠢了 哭）

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {

        boolean[][] visited = new boolean[board.length][board[0].length];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {

                //搜到的时候 提前终止，剪枝，从word的0开始搜索
                if (backtrack(i, j , board, word, visited, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean backtrack (int i, int j, char[][] board, String word, boolean[][] visited, int index) {

        //退出条件: 当搜索到 word最后一位时
        if (index == word.length() - 1) {
            return board[i][j] == word.charAt(index) ;
        }

        //当 board[i][j]匹配到 word。charAt(index). 进入下一次递归，上下左右。

        if (board[i][j] == word.charAt(index)) {   
            visited[i][j] = true;

            //向上搜索，当索引合法，且未搜寻过
            if (valid(i, j - 1, board) && !visited[i][j - 1] && backtrack(i, j - 1, board, word, visited, index + 1)){
                return true;
            }
            
            if (valid(i, j + 1, board) && !visited[i][j + 1] && backtrack(i, j + 1, board, word, visited, index + 1)) {
                return true;
            }
            
            if (valid(i - 1, j, board) && !visited[i - 1][j ] && backtrack(i - 1, j, board, word, visited, index + 1)) {
                return true;
            }
            
            if (valid(i + 1, j, board) && !visited[i + 1][j] && backtrack(i + 1, j, board, word, visited, index + 1)) {
                return true;
            }
        }
        
        //回溯
        visited[i][j] = false;
        return false;
    }

    private boolean valid (int i, int j, char[][] board) {
        return i >= 0 && j >= 0 && i < board.length && j < board[0].length;
    }

}
```
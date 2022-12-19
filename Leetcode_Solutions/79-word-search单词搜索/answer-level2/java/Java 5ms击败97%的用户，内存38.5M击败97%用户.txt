### 解题思路

![图片.png](https://pic.leetcode-cn.com/f9bac41100d9c1a7fd8ab0bcbcab8fd36035da5065eb79ef50debf1fb0129405-%E5%9B%BE%E7%89%87.png)

就是DFS，其他没啥，这个时间复杂度是个问题，列出一些优化点供参考：

**1、不要在循环里定义变量，我这里的v一开始在双层循环内部，导致速度很慢。**
**2、定义了一个stop，用来提前结束dfs。**
**3、判断后再递归，节省一次函数调用，java函数调用会多一个栈帧。**
**4、简化逻辑+适当运用逻辑短路，加速判断。**
**5、貌似从后往前循环会快一点，这个跟答案位置有关，尝试的出来的结论。**

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        if (word == null || word.length() == 0) return true;
        if (board == null || board.length == 0 || board[0].length == 0 || 
        board[0].length*board.length < word.length()) return false;
        boolean[][] v = new boolean[board.length][board[0].length];
        int[] stop = new int[1];
        for (int i = board.length - 1; i >= 0; i--) {
            for (int j = board[i].length - 1; j >= 0; j--) {
                if (board[i][j] != word.charAt(0)) continue;
                v[i][j] = true;
                if (exist(board, word, i, j, 0, v, stop)) return true;
                v[i][j] = false;
            }
        }
        return false;
    }
    private boolean exist(char[][] board, String word, int i, int j, int index, boolean[][] v, int[] stop){
        if (stop[0] == 1 || index == word.length() - 1){
            stop[0] = 1;
            return true;
        }
        if (index >= word.length() || board[i][j] != word.charAt(index)) return false;
        boolean flag = false;
        if (i + 1 < board.length && !v[i + 1][j] && board[i + 1][j] == word.charAt(index + 1)) {
            v[i + 1][j] = true;
            flag |=  exist(board, word, i + 1, j, index + 1, v, stop);
            v[i + 1][j] = false;
        }
        if (j + 1 < board[i].length && !v[i][j + 1] && board[i][j + 1] == word.charAt(index + 1)) {
            v[i][j + 1] = true;
            flag |=  exist(board, word, i, j + 1, index + 1, v, stop);
            v[i][j + 1] = false;
        }
        if (i > 0 && !v[i - 1][j] && board[i - 1][j] == word.charAt(index + 1)) {
            v[i - 1][j] = true;
            flag |=  exist(board, word, i - 1, j, index + 1, v, stop);
            v[i - 1][j] = false;
        }
        if (j > 0 && !v[i][j - 1] && board[i][j - 1] == word.charAt(index + 1)) {
            v[i][j - 1] = true;
            flag |=  exist(board, word, i, j - 1, index + 1, v, stop);
            v[i][j - 1] = false;
        }
        return flag;
    }
}
```
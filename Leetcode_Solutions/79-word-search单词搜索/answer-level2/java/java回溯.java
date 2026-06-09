### 解题思路
使用使用visited数组记录每个位置有没有被访问过，每到一个位置，继续向四周试探。

### 代码

```java
class Solution {
    boolean[][] visited;
    int iLen, jLen;

    public boolean exist(char[][] board, String word) {

        if (board == null || board.length == 0 ||
                board[0] == null || board[0].length == 0 ||
                word == null || word.length() == 0) {
            return false;
        }

        iLen = board.length;
        jLen = board[0].length;
        visited = new boolean[iLen][jLen];

        for (int i = 0; i < iLen; i++) {
            for (int j = 0; j < jLen; j++) {
                if (existHelp(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean existHelp(char[][] board, int i, int j, String word, int index) {

        if (board[i][j] != word.charAt(index) || visited[i][j] == true) {
            return false;
        }
        visited[i][j] = true;
        if (index == word.length() - 1) { // 最后一个字符匹配上了，直接结束
            return true;
        }
        if (i > 0 && existHelp(board, i - 1, j, word, index + 1)) {
            return true;
        }
        if (i < iLen - 1 && existHelp(board, i + 1, j, word, index + 1)) {
            return true;
        }
        if (j > 0 && existHelp(board, i, j - 1, word, index + 1)) {
            return true;
        }
        if (j < jLen - 1 && existHelp(board, i, j + 1, word, index + 1)) {
            return true;
        }
        visited[i][j] = false; // 还原现场，这次不成，下种情况还有机会
        return false;
    }
}
```
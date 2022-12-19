### 解题思路
思路如代码注释。

### 代码

```java
class Solution {
    private boolean[][] visited;
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0) {
            return false;            
        }
        int rows = board.length;
        int cols = board[0].length;
        visited = new boolean[rows][cols];

        // 双重循环是为了每一个位置都可以作为起点进行字符串的寻找！！！
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 如果找到一条路径则直接返回true即可
                if (findPath(board, rows, cols, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean findPath(char[][] board, int rows, int cols,
                             int row, int col, String word, int index) {
        // 首先是否已经字符串已经找到，即长度已经遍历完
        if (index == word.length()) {
            return true;
        }
        // 需要检查当前index字符是否是路径当前需要的字符之前，先检查坐标合法性以及是否已经被访问过
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col]) {
            return false;
        }
        // 如果当前坐标的字符不是所找字符，则直接false
        if (board[row][col] != word.charAt(index)) {
            return false;
        }

        // 更新此坐标元素位置为true：已访问
        visited[row][col] = true;
        // 查看四个方向是否存在下一个字符，递归进行
        boolean flag = findPath(board, rows, cols, row - 1, col, word, index + 1) 
            || findPath(board, rows, cols, row + 1, col, word, index + 1)
            || findPath(board, rows, cols, row, col - 1, word, index + 1)
            || findPath(board, rows, cols, row, col + 1, word, index + 1);
        // 递归完成后，将此位置释放，便于下次继续寻找
        visited[row][col] = false;
        return flag;
    }
}
```
### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :41.9 MB, 在所有 Java 提交中击败了44.09%的用户

很麻烦的做法，不过看结果还行的样子
首先确定，边界的'O'和与边界的'O'相连的'O'是需要保留的，那么先定义一个方法searchNear，该方法在找到了边界的'O'后，对这个边界的'O'周围的元素进行递归寻找，找到与之相连的'O'，暂时修改成为'T'（temple）,全部改完之后就可以对board进行遍历了，把所有的'O'删掉，所有的'T'变成'O'
多次用到遍历，感觉复杂度挺大的……

### 代码

```java
class Solution {
        public void solve(char[][] board) {
        int m = board.length;
        if (m == 0){
            return;
        }
        int n = board[0].length;
        if (n == 0){
            return;
        }
        Solution solution = new Solution();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                solution.searchNear(i, 0, board);
            }
            if (board[i][n - 1] == 'O') {
                solution.searchNear(i, n - 1, board);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O'){
                solution.searchNear(0, i, board);
            }
            if (board[m - 1][i] == 'O'){
                solution.searchNear(m - 1, i, board);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if (board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    private void searchNear(int x, int y, char[][] board){
        board[x][y] = 'T';
        if (x - 1 >= 0){
            if (board[x - 1][y] == 'O'){
                board[x - 1][y] = 'T';
                searchNear(x - 1, y, board);
            }
        }
        if (y - 1 >= 0){
            if (board[x][y - 1] == 'O'){
                board[x][y - 1] = 'T';
                searchNear(x, y - 1, board);
            }
        }
        if (x + 1 < board.length){
            if (board[x + 1][y] == 'O'){
                board[x + 1][y] = 'T';
                searchNear(x + 1, y, board);
            }
        }
        if (y + 1 < board[0].length){
            if (board[x][y + 1] == 'O'){
                board[x][y + 1] = 'T';
                searchNear(x, y + 1, board);
            }
        }
    }
}
```

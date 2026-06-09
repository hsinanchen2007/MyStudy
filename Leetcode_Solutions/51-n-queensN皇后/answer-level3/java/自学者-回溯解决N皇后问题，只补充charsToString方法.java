### 解题思路
* 参考其他大佬的解题思路
* 关键点在于往左上角和右上角移动的方法
* 自己实现了charToString的方法
* 构造函数初始化的目的在调用该类的时候不进行内存分配加载
* 注意棋盘初始化的方法

### 代码

```java
class Solution {
        private List<List<String>> result;
        Solution() {
            // 构造函数初始化的目的在调用该类的时候不进行内存分配加载
            this.result = new LinkedList<>();
        }
        public List<List<String>> solveNQueens(int n) {
            if (n <= 0) {
                return null;
            }

            char[][] board = new char[n][n];
            for (char[] chars : board) {
                Arrays.fill(chars, '.');
            }
            backtrack(board, 0);
            return result;
        }

        /**
         * 路径：board中小于row的那些行都已经成功放置了皇后
         * 可选择列表: 第row行的所有列都是放置Q的选择
         * 结束条件: row超过board的最后一行
         *
         * @param board 棋盘
         * @param row 当前正在第几行放置皇后
         */
        private void backtrack(char[][] board, int row) {
            if (row == board.length) {
                result.add(charToString(board));
                return;
            }
            int n = board[row].length;
            for (int col = 0; col < n; col++) {
                if (!isValid(board, row, col)) {
                    continue;
                }
                board[row][col] = 'Q';
                backtrack(board, row + 1);
                board[row][col] = '.';
            }
        }
        
        private List<String> charToString(char[][] board) {
            List<String> ans = new ArrayList<>();
            StringBuilder sb = null;
            for (int i = 0; i < board.length; i++) {
                sb = new StringBuilder();
                for (int j = 0; j < board[0].length; j++) {
                    sb.append(board[i][j]);
                }
               ans.add(sb.toString()); 
            }
            return ans;
        }
        private boolean isValid(char[][] board, int row, int col) {
            int rows = board.length;
            // 检查当前列是否存在其他皇后，check is valid in col
            for (char[] chars : board) {
                if (chars[col] == 'Q') {
                    return false;
                }
            }
            // 检查右上角是否有皇后，右下脚还没走过肯定没有皇后 check is valid upright
            for (int i = row - 1, j = col + 1; i >= 0 && j < rows; i--, j++) {
                if (board[i][j] == 'Q') return false;
            }
            // 检查左上角是否有皇后，左下脚还没走过肯定没有皇后 check is valid upleft
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') return false;
            }
            return true;
        }
}
```
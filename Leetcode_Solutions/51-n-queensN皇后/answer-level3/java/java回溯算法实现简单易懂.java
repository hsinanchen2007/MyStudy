### 解题思路
java回溯算法实现

### 代码

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
        // 初始化棋盘，赋初值
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }

        List<List<String>> results = new ArrayList<List<String>>();
        backTrack(board, 0, n, results);
        return results;
    }

    private void backTrack(char[][] board, int row, int n, List<List<String>> results) {
        if (row == n) {
            // 这条路走完了，记录结果
            results.add(toList(board));
        }

        for (int col = 0; col < board[0].length; col++) {
            //枚举所有的选择
            if (!checkValidPath(board, row, col)) {
                // 路径冲突，剪枝
                continue;
            }
            // 路径不冲突，选择
            board[row][col] = 'Q';
            // 继续进行递归，row+1
            backTrack(board, row+1, n, results);
            // 撤销选择，回溯
            board[row][col] = '.';
        }
    }

    /**
     * 检查皇后之间是否不能互相攻击
     * @param board 当前棋盘情况
     * @param row 行
     * @param col 列
     * @return 满足返回true
     */
    private boolean checkValidPath(char[][] board, int row, int col) {
        int n = board[0].length;
        // 同一列不能有皇后
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // 左上方不能有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // 右上方不能有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--,j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    /**
     * char数组转成List
     * @param board
     * @return
     */
    private List<String> toList(char[][] board) {
        List<String> list = new ArrayList<String>();
        for (int i = 0; i < board[0].length; i++) {
            list.add(new String(board[i]));
        }
        return list;
    }
}
```
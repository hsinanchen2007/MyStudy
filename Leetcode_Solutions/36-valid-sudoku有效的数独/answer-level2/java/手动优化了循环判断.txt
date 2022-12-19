### 解题思路
第一个循环时间复杂度O(n^2),验证横竖是否有重复。
第一个循环时间复杂度也是O(n^2),验证子方块是否有重复。

执行用时和消耗内存竟然不如之前那个暴力法。。。
### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        List<Character> rows;
        List<Character> cols;

        for (int i=0; i < 9; i++) {
            rows = new ArrayList<>();
            cols = new ArrayList<>();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rows.contains(board[i][j])) {
                        return false;
                    }
                    rows.add(board[i][j]);
                }
                if(board[j][i] != '.'){
                    if (cols.contains(board[j][i])) {
                        return false;
                    }
                    cols.add(board[j][i]);
                }

            }
        }

        List<Character> cells;
        for (int j = 0; j < 9; j+=3) {
            for (int k = 0; k < 9; k+=3) {
                cells = new ArrayList<>();
                for (int row = j; row < j + 3; row++) {
                    for (int col = k; col < k + 3; col++) {
                        if (board[row][col] != '.') {
                            if (cells.contains(board[row][col])) {
                                return false;
                            }
                            cells.add(board[row][col]);
                        }
                    }
                }
            }
        }
        return true;
    }
}
```
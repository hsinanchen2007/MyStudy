### 解题思路
1. 横线上不能有重复数字
2. 竖线上不能有重复数字
3. 3*3方格内不能有重复数字
    1. 开始 i / 3 * 3 ( j / 3 * 3 )
    2. 结束 i / 3 * 3 + 3 ( j / 3 * 3 + 3 )

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int n = 9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char cur = board[i][j];
                if (cur != '.') {
                    // 横线上不能有重复数字
                    for (int k = 0; k < n; k++) {
                        if (k == j) continue;
                        if (board[i][k] == cur) {
                            return false;
                        }
                    }

                    // 竖线上不能有重复数字
                    for (int k = 0; k < n; k++) {
                        if (k == i) continue;
                        if (board[k][j] == cur) {
                            return false;
                        }
                    }

                    // 3*3方格内不能有重复数字
                    int rowStart = i / 3 * 3;
                    int rowEnd = i / 3 * 3 + 3;
                    int columnStart = j / 3 * 3;
                    int columnEnd = j / 3 * 3 + 3;
                    for (int x = rowStart; x < rowEnd; x++) {
                        for (int y = columnStart; y < columnEnd; y++) {
                            if (x == i && y == j) continue;
                            if (board[x][y] == cur) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
}
```
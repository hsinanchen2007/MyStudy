### 解题思路
和官方的思路一样，只不过简化了map的使用，减少了put，get的次数，代码简洁。

### 代码

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashMap<Integer, Integer>[] rows = new HashMap[9];
        HashMap<Integer, Integer>[] columns = new HashMap[9];
        HashMap<Integer, Integer>[] boxes = new HashMap[9];

        for (int i = 0; i < 9; i++) {
            rows[i] = new HashMap<>();
            columns[i] = new HashMap<>();
            boxes[i] = new HashMap<>();
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int key = board[i][j];
                    int boxIdx = (i / 3) * 3 + j / 3;

                    if (rows[i].merge(key, 1, (a, b) -> a + b) > 1) {
                        return false;
                    }
                    if (columns[j].merge(key, 1, (a, b) -> a + b) > 1) {
                        return false;
                    }
                    if (boxes[boxIdx].merge(key, 1, (a, b) -> a + b) > 1) {
                        return false;
                    }

                }
            }
        }
        return true;
    }
}
```
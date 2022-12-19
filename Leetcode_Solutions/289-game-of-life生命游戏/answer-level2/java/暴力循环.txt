### 解题思路
```text
1. 增加辅助数组，记录需要修改值的位置
2. 判断当前元素周围存活的细胞个数，然后根据题意判断是否需要变更值
3. 遍历到最后，一次性修改所有位置的值
```

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        // 处理边界条件
        if (board.length == 0) {
            return;
        }
        // 更新flag，true表示更新该细胞位置的值，false表示不更新
        boolean[][] changeFlag = new boolean[board.length][board[0].length];
        // 遍历细胞
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                // 获取该细胞位置周围活细胞个数
                int num = getLiveCellNum(board, i, j);
                // 活细胞变更的场景
                if (board[i][j] == 1) {
                    // 活细胞周围的活细胞如果少于2个，则活细胞死亡
                    if (num < 2) {
                        changeFlag[i][j] = true;
                    }
                    // 活细胞周围的活细胞大于3个，则活细胞死亡
                    if (num > 3) {
                        changeFlag[i][j] = true;
                    }

                } else {
                    // 死细胞周围有3个活细胞，则死细胞复活
                    if (num == 3) {
                        changeFlag[i][j] = true;
                    }
                }
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                // 如果修改标志位为true，则更新细胞值
                if (changeFlag[i][j]) {
                    if (board[i][j] == 0) {
                        board[i][j] = 1;
                    } else {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    private int getLiveCellNum(int[][] board, int i, int j) {
        // 八个方向
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        // 记录个数
        int count = 0;
        for (int[] dir : dirs) {
            int posX = i + dir[0];
            int posY = j + dir[1];
            // 判断是否越界
            if (posX < 0 || posX >= board.length || posY < 0 || posY >= board[0].length) {
                continue;
            }
            // 如果为存活的细胞，个数递增
            if (board[posX][posY] == 1) {
                count++;
            }
        }
        return count;
    }
}

```

### 测试用例
```java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void gameOfLife() {
        int[][] input1 = {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
        int[][] expect1 = {{0,0,0}, {1,0,1}, {0,1,1}, {0,1,0}};
        solution.gameOfLife(input1);
        assertArrayEquals(input1, expect1);
    }
}
```
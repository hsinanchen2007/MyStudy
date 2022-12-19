### 解题思路
此处撰写解题思路
三个数组来标记每行、每列及每个区域内数字是否被使用。
empty列表来记录没有数字的坐标。
backtrack递归回溯。（iter表示当前判断的是empty的坐标。如果empty.size()等于iter表示已经递归结束，返回结果。）
for (int i = 0; i < 9; i++) 选出当前行、当前列及区域内都未被使用的坐标。
backtrack(iter+1)寻找下一个坐标。如果下次查找中i都不能满足行、列及区域内都未被使用，则回溯到上一次查找。

### 代码

```java
class Solution {
    private boolean[][] rowNums = new boolean[9][9];
    private boolean[][] colNums = new boolean[9][9];
    private boolean[][] areaNums = new boolean[9][9];
    private List<Integer[]> empty = new ArrayList<>();
    private char[][] board;

    public void solveSudoku(char[][] board) {
        this.board = board;
        for (int i = 0; i < board.length; i++) {
            char[] line = board[i];
            for (int j = 0; j < line.length; j++) {
                char c = line[j];
                if (c == '.') {
                    empty.add(new Integer[]{i, j});
                } else {
                    int num = Integer.parseInt(String.valueOf(c)) - 1;
                    rowNums[i][num] = true;
                    colNums[j][num] = true;
                    areaNums[i / 3 * 3 + j / 3][num] = true;
                }
            }
        }
        backtrack(0);
    }

    public boolean backtrack(int iter) {
        if (empty.size() == iter) {
            return true;
        }
        Integer[] coordinate = empty.get(iter);
        int row = coordinate[0], col = coordinate[1];
        int area = row / 3 * 3 + col / 3;
        for (int i = 0; i < 9; i++) {
            if (!rowNums[row][i] && !colNums[col][i] && !areaNums[area][i]) {
                rowNums[row][i] = true;
                colNums[col][i] = true;
                areaNums[area][i] = true;
                if (this.backtrack(iter + 1)) {
                    this.board[row][col] = (char) ('0' + i + 1);
                    return true;
                }
                rowNums[row][i] = false;
                colNums[col][i] = false;
                areaNums[area][i] = false;
            }
        }
        return false;
    }
}
```
### 解题思路
每一个皇后的出现，导致对角线和反对角线，以及十字线内不能出现皇后，由于使用了回溯，逻辑上避免了同一行出现皇后，
所以只需要记录出现过的对角线和反对角线以及，出现的Column就行了
![image.png](https://pic.leetcode-cn.com/6a5f77026483586099bad7717af17cb842929d26c6d711356114b9bce01e1183-image.png)


### 代码

```java
class Solution {
    private char[][] pos;
    private int N;
    int[] rcSumSet;//行和列的差   //对角线为y = x + n  (n为一个有关上下文的数)
    int[] rcDisSet;//行和列的和   //反对角线为y = -x + m （m为一个有关上下文的数）
    int[] cAppearSet;//出现的列
    List<List<String>> result = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
        if (n == 0) return result;
        pos = new char[n][n];
        this.N = n;
        rcSumSet = new int[2 * N - 1];//共有2*N-1种对角线
        rcDisSet = new int[2 * N - 1];//共有2*N-1种反对角线
        cAppearSet = new int[N];
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) pos[i][j] = '.';
        //开始回溯
        backtraceRow(0);
        return result;
    }

    private void backtraceRow(int row) {
        if (row == N) return;
        for (int column = 0; column < N; column++) {
            boolean canInsert = checkSet(row, column);
            if (canInsert) {
                putOrRemoveSetElement(row, column, true);
                pos[row][column] = 'Q';
                if (row + 1 == N) {
                    List<String> itemResult = new ArrayList<>();
                    for (int i = 0; i < N; i++) {
                        StringBuilder sb = new StringBuilder();
                        for (int j = 0; j < N; j++) sb.append(pos[i][j]);
                        itemResult.add(sb.toString());
                    }
                    result.add(itemResult);
                } else {
                    backtraceRow(row + 1);
                }
                pos[row][column] = '.';//恢复数组
                putOrRemoveSetElement(row, column, false);
            }
        }
    }

    private boolean checkSet(int row, int column) {
        if (cAppearSet[column] == 1) return false;
        else if (rcSumSet[row + column] == 1) return false;
        else if (rcDisSet[N - 1 - row + column] == 1) return false;
        else return true;
    }

    private void putOrRemoveSetElement(int row, int column, boolean isPut) {
        if (isPut) {
            cAppearSet[column] = 1;
            rcSumSet[row + column] = 1;
            rcDisSet[N - 1 - row + column] = 1;
        } else {
            cAppearSet[column] = 0;
            rcSumSet[row + column] = 0;
            rcDisSet[N - 1 - row + column] = 0;
        }
    }
}
```
### 解题思路
执行用时 :2 ms, 在所有 java 提交中击败了61.57%的用户
内存消耗 :33.1 MB, 在所有 java 提交中击败了56.56%的用户

### 代码

```java
class Solution {
    //一维数组，下标表示行，值表示列
    int[] rec;
    int ans;
    int n;

    public int totalNQueens(int _n) {
        n = _n;
        rec = new int[n];

        // 从第1行开始放皇后
        dfs(0);
        return ans;
    }

    private void dfs(int row) {

        // 所有行都遍历完了，那么结果就+1
        if (row == n) {
            ans++;
            return;
        }

        // 从第一列开始遍历所有列
        for (int col = 0; col < n; col++) {

            // 尝试将皇后放到第row行 第col列
            if (check(row, col)) {

                // 将皇后放到 第row行 第col列
                rec[row] = col;

                // 深搜下一行(这一行的皇后放下了，该放下一行了)
                dfs(row + 1);
            }
        }
    }

    /**
     * 检查是否能将皇后放在第row行，第col列
     *
     * @param row
     * @param col
     * @return true 表示可以放；反之false表示不能放
     */
    private boolean check(int row, int col) {

        // 遍历row行之前的所有行
        for (int i = 0; i < row; i++) {
            // 1. 第i行已经放过皇后了，在第col列(即第col列已经放过皇后了)
            // 2. 第i行 + 第i行的列(正对角线)
            // 3. 反对角线

            // 三个筛选条件分别针对 不能同列、不能同正对角线、不能同反对角线进行了处理（因一行只能放一个皇后所以不需要对"不能同行"做额外处理)
            if (rec[i] == col || i + rec[i] == row + col || rec[i] - i == col - row) {
                return false;
            }
        }
        return true;
    }
}
```
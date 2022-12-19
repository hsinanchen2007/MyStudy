### 解题思路

- 暴力执行逻辑，计算结果
- 通过统计行，列的操作次数，可以得出二维数组中每个位操作了几次，将行列操作次数加起来 % 2 ！= 0的则为奇数

### 代码

```java
class Solution {
        /**
     * 直接计算得出结果
     * @param n
     * @param m
     * @param indices
     * @return
     */
    public int oddCellsNew(int n, int m, int[][] indices) {
        int[][] arr = new int[n][m];

        for (int i = 0; i < indices.length; i++) {
            // 指定行indices[i][0]的值 ++
            int row = indices[i][0];
            for (int j = 0; j < arr[row].length; j++) {
                arr[row][j] ++;
            }
            // 指定列indices[i][1]的值 ++
            int column = indices[i][1];
            for (int j = 0; j < arr.length; j++) {
                arr[j][column] ++;
            }
        }

        int num = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] % 2 != 0) {
                    num ++;
                }
            }
        }

        return num;
    }
    /**
     * 统计行数和列数出现的结果
     * @param n
     * @param m
     * @param indices
     * @return
     */
    public int oddCells(int n, int m, int[][] indices) {
        int[] row = new int[n];
        int[] col = new int[m];

        /**
         * 通过统计行，列的操作次数，可以得出二维数组中每个位操作了几次，将行列操作次数加起来 % 2 ！= 0的则为奇数
         */
        for (int i = 0; i < indices.length; i++) {
            row[indices[i][0]] ++;
            col[indices[i][1]] ++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((row[i] + col[j]) % 2 != 0) {
                    ans ++;
                }
            }
        }

        return ans;
    }
}
```
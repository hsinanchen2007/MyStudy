# 思路
暴力枚举上下边，将问题转为[最大子数组和问题](https://leetcode-cn.com/problems/maximum-subarray/)。

# 代码
```java
class Solution {
    private int max_sum = Integer.MIN_VALUE, global_col;
    private int[] res = new int[4];
    private int[][] pre_sum;

    public int[] getMaxMatrix(int[][] matrix) {
        int row = matrix.length;
        global_col = matrix[0].length;
        pre_sum = new int[row + 1][global_col];
        for (int j = 0; j < global_col; ++j)
            for (int i = 1; i <= row; ++i)
                pre_sum[i][j] = matrix[i - 1][j] + pre_sum[i - 1][j];

        for (int b_row = 0; b_row <= row; ++b_row)
            for (int e_row = b_row + 1; e_row <= row; ++e_row)
                compute(b_row, e_row);

        return res;
    }

    private void compute(int r1, int r2) {
        int sum = 0, c1 = 0, c2 = 0;
        for (; c2 < global_col; ++c2) {
            sum += pre_sum[r2][c2] - pre_sum[r1][c2];
            if (max_sum < sum) {
                res[0] = r1;
                res[1] = c1;
                res[2] = r2 - 1;
                res[3] = c2;
                max_sum = sum;
            }
            if (sum < 0) {
                sum = 0;
                c1 = c2 + 1;
            }
        }
    }
}
```

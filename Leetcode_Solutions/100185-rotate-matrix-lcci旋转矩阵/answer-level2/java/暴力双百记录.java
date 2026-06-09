# 提交完看到双百我是拒绝的。这个如此暴力的写法性能竟然是最高的嘛？
![1.png](https://pic.leetcode-cn.com/a1bb55edbf82a5233d4dd9411e89e9aa6cc714807c432ac0f2b35a686edf4aeb-1.png)


```
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int[][] result = new int[n][n];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                result[j][n - i - 1] = matrix[i][j];
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                matrix[i][j] = result[i][j];
            }
        }
    }
}
```

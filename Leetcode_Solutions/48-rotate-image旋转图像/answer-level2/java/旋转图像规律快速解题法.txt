```java
/**
* 欢迎关注公众号: 算法小生
* 陪你一起leetcode
*/
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        /**
         * 把矩形分为四部分，上下左右，首先存储左边，然后顺时针开始旋转赋值
         * 则左边 下->上，行减小，列不变 matrix[n-1-j][i]
         *  下边 右->左，行不变，列减小 matrix[n-1-i][n-1-j] 该列与上边行相同均为n-1-j
         *  右边 上->下，行增大，列不变 matrix[j][n-1-i] 该列与上边行相同均为n-1-i
         *  上边 左->右，行不变，列增大 matrix[i][j] 该列与上边行相同均为j
         * 不知是否发现规律，无非就是 i,j,n-1-i,n-1-j 行与列组合, 下次直接记住左边matrix[n-1-j][i]，并记住上面的规律即可快速解题
         */
        for (int i = 0; i < (n + 1) / 2; i ++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
}
```

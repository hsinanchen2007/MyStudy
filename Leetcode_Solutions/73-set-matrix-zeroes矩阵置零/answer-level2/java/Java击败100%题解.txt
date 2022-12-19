- ![clipboard.png](https://pic.leetcode-cn.com/e5f3bead7175d628b769fff8bd608e8d87ce4d889b426e9e8259f02b899c2b1c-clipboard.png)


```
class Solution {
    public void setZeroes(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        // 前一行为0标志
        boolean isLastRowZero = false;
        for (int i = 0; i < matrix.length; i ++) {
            // 当前行为0标志
            boolean isCurrRowZero = false;
            for (int j = 0; j < matrix[0].length; j ++) {
                if (matrix[i][j] == 0) {
                    isCurrRowZero = true;
                    // 纵向上一个值不是零，说明纵向第一次出现零，需要把纵向前面的值都置为零
                    if (i > 0 && matrix[i - 1][j] != 0) {
                        for (int k = 0; k < i; k ++) {
                            matrix[k][j] = 0;
                        }
                    }
                }
                // 纵向上一个值如果为零，则把纵向的零延伸到此行
                else if (i > 0 && matrix[i - 1][j] == 0){
                    matrix[i][j] = 0;
                }
                
                // 如果上一行为零标志为真,则上一行这个位置置为零（纵向为零的判断在上面处理过，所以到这里才可以设置为0）
                if (isLastRowZero) {
                    matrix[i - 1][j] = 0;
                }
            }
            isLastRowZero = isCurrRowZero;
        }

        // 处理最后一行为零的情况
        if (isLastRowZero) {
            for (int i = 0; i < matrix[0].length; i ++) {
                matrix[matrix.length - 1][i] = 0;
            }
        }
    }
}
```

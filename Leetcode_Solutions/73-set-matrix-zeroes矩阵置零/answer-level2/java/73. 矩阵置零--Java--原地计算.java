[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_73_setZeroes.java)

```java
    /**
     * 难点在于：使用常数空间，我们先来看不适用常数空间咋解决
     * O(mn)：直接生成一个同等大小的矩阵，遍历原始矩阵，遇0将新矩阵横竖都设置为0
     * O(m+n)：两个set分别保存有0的横和竖列，遍历结束直接将set中的横竖设0
     * 解题思路：
     * 1、利用矩阵的第一行和第一列保存有0的行和列
     * 2、需要考虑下特殊情况的[0,0]，这个位置可能是横列、纵列、自身导致赋的0
     *
     * 执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
     * 内存消耗 :43.3 MB, 在所有 java 提交中击败了97.83%的用户
     *
     * @param matrix
     */
    public void setZeroes(int[][] matrix) {
        boolean isCol = false;
        int row = matrix.length;
        int col = matrix[0].length;

        //使用第一行、第一列标记0
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //横、竖列置0
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] ==0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        //[0,0]为0的时候，需要特殊判断下是横还是纵
        if (matrix[0][0] == 0) {
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }

        if (isCol) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
```
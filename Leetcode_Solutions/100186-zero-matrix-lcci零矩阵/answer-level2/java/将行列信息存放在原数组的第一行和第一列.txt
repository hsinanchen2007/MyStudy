1. 需要设零的行`i`：将该行的第一列元素`matrix[i][0]`设为0，表示该行需要清零；
2. 需要设为零的列`j`：将该列的第一行元素`matrix[0][j]`设为0，表示该列需要清零；
3. 根据第一行和第一列的标记，进行清零操作。
> `matrix[0][0]即表示第一行又表示第一列,需要特殊处理`  


```
class Solution {
    public void setZeroes(int[][] matrix) {
        boolean shu = false;
        boolean hen = false;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        hen = true;
                    }
                    if (j == 0) {
                        shu = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.length; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[0].length; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix[0].length; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < matrix.length; j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        if (shu) {
            for (int i = 0; i < matrix.length; i++) {
                matrix[i][0] = 0;
            }
        }
        if (hen) {
            for (int i = 0; i < matrix[0].length; i++) {
                matrix[0][i] = 0;
            }
        }
    }
}
```

1、分别标记第一行、第一列，是否包含0；
2、遍历除第一行和第一列以外的所有元素，若为0，将该元素所在第一行、第一列置0；
3、分别遍历第一行、第一列，若元素为0，将该元素所在列或行置0；
4、根据第1步的标记，来决定是否将第一行、第一列置0。
```
 public void setZeroes2(int[][] matrix) {
        boolean firstRowHasZero = false;
        for (int i = 0; i < matrix[0].length; ++i) {
            if (matrix[0][i] == 0) {
                firstRowHasZero = true;
                break;
            }

        }
        boolean firstColHasZero = false;
        for (int i = 0; i < matrix.length; ++i) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }
        for (int i = 1; i < matrix.length; ++i) {
            for (int j = 1; j < matrix[0].length; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix[0].length; ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < matrix.length; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.length; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[0].length; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowHasZero) {
            for (int i = 0; i < matrix[0].length; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (firstColHasZero) {
            for (int i = 0; i < matrix.length; ++i) {
                matrix[i][0] = 0;
            }
        }


    }
```

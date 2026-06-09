```
 public void rotate(int[][] matrix) {
        int len = matrix.length >> 1;
        for(int j = 0; j < len; j++) {
            int ll = matrix.length - 1 - 2 * j;
            for (int i = 0; i < ll; i++) {
                int temp = matrix[j][i + j];
                matrix[j][i + j] = matrix[matrix.length - 1 - j - i][j];
                matrix[matrix.length - 1 - j - i][j] =  matrix[matrix.length - 1 - j][matrix.length - 1 - j - i];
                matrix[matrix.length - 1 - j][matrix.length - 1 - j - i] = matrix[j + i][matrix.length - 1 - j];
                matrix[j + i][matrix.length - 1 - j] = temp;
            }
        }
    }
```

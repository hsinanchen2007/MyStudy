先转置，再旋转每一行：

```
    /**
     * 旋转图像
     *
     * @param matrix
     */
    public void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = i; j < matrix.length; j++) {
                if (i == j) {
                    continue;
                }
                swapWithTwo(matrix, i, j);
            }
        }
        rotateLine(matrix);
    }

    private void rotateLine(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            int left = 0;
            int right = matrix.length - 1;
            while (left < right) {
                swapWithOne(matrix[i], left, right);
                left++;
                right--;
            }
        }
    }

    private void swapWithTwo(int[][] matrix, int i, int j) {
        matrix[i][j] = matrix[i][j] ^ matrix[j][i];
        matrix[j][i] = matrix[j][i] ^ matrix[i][j];
        matrix[i][j] = matrix[j][i] ^ matrix[i][j];
    }

    private void swapWithOne(int[] mat, int i, int j) {
        mat[i] ^= mat[j];
        mat[j] ^= mat[i];
        mat[i] ^= mat[j];
    }
```

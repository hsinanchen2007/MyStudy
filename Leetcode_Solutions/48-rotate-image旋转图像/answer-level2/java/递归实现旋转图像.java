思路：由外向内旋转图像

    public void rotate(int[][] matrix) {
        recursiveRotate(matrix, 0);
    }

    public void recursiveRotate(int[][] matrix, int pos) {
        int n = matrix.length;
        if (n - 2 * pos > 1) {
            for (int column = pos; column < n - 1 - pos; column++) {
                int tmp = matrix[pos][column];
                matrix[pos][column] = matrix[n - 1 - column][pos];
                matrix[n - 1 - column][pos] = matrix[n - 1 - pos][n - 1 - column];
                matrix[n - 1 - pos][n - 1 - column] = matrix[column][n - 1 - pos];
                matrix[column][n - 1 - pos] = tmp;
            }
            recursiveRotate(matrix, pos + 1);
        }
    }
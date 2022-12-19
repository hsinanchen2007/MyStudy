    public void rotate(int[][] matrix) {
        int n = matrix.length - 1;
        int offset = 0;
        while (n >= 1) {
            for (int i = 0; i < n; i++) {
                int tmp = matrix[offset][offset + i];
                matrix[offset][offset + i] = matrix[n + offset - i][offset];
                matrix[n + offset - i][offset] = matrix[n + offset][n + offset - i];
                matrix[n + offset][n + offset - i] = matrix[i + offset][n + offset];
                matrix[i + offset][n + offset] = tmp;
            }
            offset += 1;
            n = n - 2;
        }
    }
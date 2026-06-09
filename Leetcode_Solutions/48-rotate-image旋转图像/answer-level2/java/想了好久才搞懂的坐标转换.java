    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int border = n - 1;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < border-i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[border - j][i];
                matrix[border - j][i] = matrix[border - i][border - j];
                matrix[border - i][border - j] = matrix[j][border - i];
                matrix[j][border - i] = temp;
            }
        }
    }
        
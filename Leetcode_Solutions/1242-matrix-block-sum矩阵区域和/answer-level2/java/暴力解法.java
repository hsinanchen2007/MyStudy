暴力解法

public int[][] matrixBlockSum(int[][] mat, int K) {
        if (mat == null) {
            return new int[0][0];
        }

        int m = mat.length;
        int n = mat[0].length;

        int[][] result = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = 0;
                for (int r = i - K; r <= i + K; r++) {
                    for (int c = j - K; c <= j + K; c++) {
                        if ((r >= 0 && r < m) && (c >= 0 && c < n)) {
                            temp += mat[r][c];
                        }
                    }
                }

                result[i][j] = temp;
            }
        }

        return result;
    }
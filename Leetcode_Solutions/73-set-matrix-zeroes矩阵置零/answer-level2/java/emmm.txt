
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        if (m == 0) return;
        int n = matrix[0].length;
        aaa(matrix, 0, 0, m, n);
    }

    private void aaa(int[][] arr, int i, int j, int m, int n) {
        while (i < m) {
            for (int k = j; k < n; k++) {
                if (arr[i][k] == 0) {
                    aaa(arr, i, k + 1, m, n);
                    for (int l = 0; l < m; l++) arr[l][k] = 0;
                    for (int l = 0; l < n; l++) arr[i][l] = 0;
                    return;
                }
            }
            j = 0;
            i++;
        }
    }
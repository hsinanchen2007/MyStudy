```
public void rotate(int[][] matrix) {
    int n = matrix.length;
    for (int j = 0; j < n / 2; j++) {
        for (int i = j; i < n - j - 1; i++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[n - i - 1][j];
            matrix[n - i - 1][j] = matrix[n - j - 1][n - i - 1];
            matrix[n - j - 1][n - i - 1] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }
}
```

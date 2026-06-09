### 解题思路
上代码

### 代码

```c
int sumOfDigits(int n) {
    int ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int movingCount(int m, int n, int k){
    int ret = 1;
    if (k == 0) {
        return ret;
    }
    int **matrix = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * n);
        memset(matrix[i], 0, sizeof(int) * n);
    }
    matrix[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 && j == 0) || (sumOfDigits(i) + sumOfDigits(j) > k)) {
                continue;
            }
            if (i >= 1) {
                matrix[i][j] |= matrix[i - 1][j];
            }
            if (j >= 1) {
                matrix[i][j] |= matrix[i][j - 1];
            }
            ret += matrix[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return ret;
}
```
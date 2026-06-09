char **g_dp = NULL;
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    char *col = NULL; 
    int i, j, min;
    int col_size = *matrixColSize;
    int sz = col_size * sizeof(char);
    int max = 0;
    int all_zero_flag = 0;
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL || *matrixColSize == 0) {
        return 0;
    }
    g_dp = (char**)malloc(sizeof(char*) * matrixSize);
    for (i = 0; i < matrixSize; i++) {
        col= (char*)malloc(sz);
        memset(col, 0x0, sz);
        g_dp[i] = col;
    }
    for (i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == '1') {
            g_dp[i][0] = 1;
            max = 1;
        }
    }
    for (i = 0; i < col_size; i++) {
        if (matrix[0][i] == '1') {
            g_dp[0][i] = 1;
            max = 1;
        }
    }
    for (i = 1; i < matrixSize; i++) {
        for (j = 1; j < col_size; j++) {
            if (matrix[i][j] == '0') {
                continue;
            }
            else {
                min = g_dp[i - 1][j] <= g_dp[i - 1][j - 1] ? g_dp[i - 1][j] : g_dp[i - 1][j - 1];
                min = g_dp[i][j - 1] <= min ? g_dp[i][j - 1] : min;
                g_dp[i][j] = min + 1;
                if (max <= g_dp[i][j]) {
                   max = g_dp[i][j];
                }
            }
        }
    }
    for (i = 0; i < matrixSize; i++) {
        free(g_dp[i]);
    }
    free(g_dp);
    return max * max;
   
}
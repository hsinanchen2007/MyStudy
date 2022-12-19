```


int** g_matrix;
char*** g_queues;
int g_num;

void alloc(int num)
{
    char*** tmp;
    int i, j;

    tmp = malloc(sizeof(char**) * g_num);
    for (i = 0; i < g_num; i++) {
        tmp[i] = malloc(sizeof(char*) * num);
        for (j = 0; j < num; j++) {
            tmp[i][j] = malloc(sizeof(char) * num + 1);
            tmp[i][j][num] = '\0';
        }
    }

    for (i = 0; i < g_num - 1; i++) {
        for (j = 0; j < num; j++) {
            memcpy(tmp[i][j], g_queues[i][j], sizeof(char) * num);
            free(g_queues[i][j]);
        }
        free(g_queues[i]);
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            tmp[g_num - 1][i][j] = '.';
            if (g_matrix[i][j]) {
                tmp[g_num - 1][i][j] = 'Q';
            }
        }
    }

    free(g_queues);
    g_queues = tmp;
    return;
}

int isValid(int row, int col, int num)
{
    int i, j;

    if (row == 0) {
        return 1;
    }

    for (i = 0; i < row; i++) {
        // 同一列有数据
        if (g_matrix[i][col]) {
            return 0;
        }
    }
    // 左上有数据
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (g_matrix[i][j]) {
            return 0;
        }
    }
    // 右上有数据
    for (i = row - 1, j = col + 1; i >= 0 && j < num; i--, j++) {
        if (g_matrix[i][j]) {
            return 0;
        }
    }

    return 1;
}

int callback(int row, int num)
{
    int i;

    if (row == num) {
        g_num++;
        alloc(num);
        return;
    }

    for (i = 0; i < num; i++) {
        g_matrix[row][i] = 1;
        if (isValid(row, i, num)) {
            callback(row + 1, num);
        }
        g_matrix[row][i] = 0;
    }

    return 0;
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    int i, j;
    int* retCol;

    g_queues = NULL;
    g_num = 0;
    g_matrix = malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        g_matrix[i] = malloc(sizeof(int) * n);
        memset(g_matrix[i], 0, sizeof(int) * n);
    }
    callback(0, n);
    for (i = 0; i < n; i++) {
        free(g_matrix[i]);
    }
    free(g_matrix);

    *returnSize = g_num;

    retCol = malloc(sizeof(int) * g_num);
    for (i = 0; i < g_num; i++) {
        retCol[i] = n;
    }

    *returnColumnSizes = retCol;

    return g_queues;
}
```
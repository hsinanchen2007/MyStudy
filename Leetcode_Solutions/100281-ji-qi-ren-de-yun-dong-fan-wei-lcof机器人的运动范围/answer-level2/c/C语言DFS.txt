```
int** record;
int gIndex;

bool isValid(int k, int i, int j)
{
    int total = 0;
    while (i > 0) {
        total += i % 10;
        i = i / 10;
    }
    while (j > 0) {
        total += j % 10;
        j = j / 10;
    }
    return total <= k;
}

void dfs(int m, int n, int k, int i, int j)
{
    record[i][j] = ++gIndex;
    if (i - 1 >= 0 && record[i-1][j] == 0 && isValid(k, i - 1, j)) {
        dfs(m, n, k, i - 1, j);
    }
    if (i + 1 < m && record[i+1][j] == 0 && isValid(k, i + 1, j)) {
        dfs(m, n, k, i + 1, j);
    }
    if (j - 1 >= 0 && record[i][j - 1] == 0 && isValid(k, i, j - 1)) {
        dfs(m, n, k, i, j - 1);
    }
    if (j + 1 < n && record[i][j + 1] == 0 && isValid(k, i, j + 1)) {
        dfs(m, n, k, i, j + 1);
    }
    return;
}

int movingCount(int m, int n, int k){
    record = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        record[i] = (int*)malloc(sizeof(int) * n);
        memset(record[i], 0, sizeof(int) * n);
    }
    gIndex = 0;
    dfs(m, n, k, 0, 0);
    return gIndex ;
}
```

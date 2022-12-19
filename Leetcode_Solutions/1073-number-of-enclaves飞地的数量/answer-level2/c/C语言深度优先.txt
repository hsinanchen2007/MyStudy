void dfs(int **A, int ASize, int *AColSize, int r, int c)
{
    if (r < 0 || r >= ASize || c < 0 || c >= *AColSize) {
        return;
    }

    if (A[r][c] == 1) {
        A[r][c] = 2;
        dfs(A, ASize, AColSize, r - 1, c);
        dfs(A, ASize, AColSize, r + 1, c);
        dfs(A, ASize, AColSize, r, c - 1);
        dfs(A, ASize, AColSize, r, c + 1);
    }
}

int numEnclaves(int** A, int ASize, int* AColSize){
    if (A == NULL || ASize == 0 || *AColSize == 0) {
        return 0;
    }
    int max = 0;
    for (int i = 0; i < *AColSize; i++) {
        dfs(A, ASize, AColSize, 0, i);
        dfs(A, ASize, AColSize, ASize - 1, i);
    }
    for (int i = 0; i < ASize; i++) {
        dfs(A, ASize, AColSize, i, 0);
        dfs(A, ASize, AColSize, i, *AColSize - 1);
    }
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < *AColSize; j++) {
            if (A[i][j] == 1) {
                max++;
            }
        }
    }
    return max;
}
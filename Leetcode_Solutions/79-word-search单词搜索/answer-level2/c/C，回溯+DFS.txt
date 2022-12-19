```
bool helper(char** board,
            int i,
            int j,
            int m,
            int n,
            char* word,
            int k,
            int** visited) {
    visited[i][j] = 1;
    // printf("i = %d, j = %d, k = %d\n", i, j, k);
    if (word[k + 1] == '\0')
        return true;
    bool isFind = false;
    if (i + 1 < m && board[i + 1][j] == word[k + 1] && !visited[i + 1][j] &&
        !isFind)
        isFind = helper(board, i + 1, j, m, n, word, k + 1, visited);
    if (j + 1 < n && board[i][j + 1] == word[k + 1] && !visited[i][j + 1] &&
        !isFind)
        isFind = helper(board, i, j + 1, m, n, word, k + 1, visited);
    if (i - 1 >= 0 && board[i - 1][j] == word[k + 1] && !visited[i - 1][j] &&
        !isFind)
        isFind = helper(board, i - 1, j, m, n, word, k + 1, visited);
    if (j - 1 >= 0 && board[i][j - 1] == word[k + 1] && !visited[i][j - 1] &&
        !isFind)
        isFind = helper(board, i, j - 1, m, n, word, k + 1, visited);
    if (!isFind)
        visited[i][j] = 0;
    return isFind;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    bool isExisted = false;
    int i, j, **visited;

    visited = (int**)malloc(sizeof(int*) * boardSize);
    for (i = 0; i < boardSize; i++)
        visited[i] = (int*)calloc((*boardColSize), sizeof(int));

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            if (board[i][j] == word[0] &&
                helper(board, i, j, boardSize, *boardColSize, word, 0,
                       visited)) {
                isExisted = true;
                // printf("i = %d, j = %d\n", i, j);
                break;
            }
        }
    }

    for (i = 0; i < boardSize; i++)
        free(visited[i]);
    free(visited);

    return isExisted;
}
```

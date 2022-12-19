```

void SubFuncDFS(int **graph, int boardSize, int* boardColSize, int i, int j) {

    if (graph[i][j] == 0) {
        graph[i][j] = 2;

        if (i > 0) {
            if (graph[i - 1][j] == 0) {
                SubFuncDFS(graph, boardSize, boardColSize, i - 1, j);
            }        
        }
        if (i < boardSize - 1) {
            if (graph[i + 1][j] == 0) {
                SubFuncDFS(graph, boardSize, boardColSize, i + 1, j);
            }        
        }
        if (j > 0) {
            if (graph[i][j - 1] == 0) {
                SubFuncDFS(graph, boardSize, boardColSize, i, j - 1);
            }        
        }
        if (j < *boardColSize - 1) {
            if (graph[i][j + 1] == 0) {
                SubFuncDFS(graph, boardSize, boardColSize, i, j + 1);
            }        
        }
    }
}

void solve(char** board, int boardSize, int* boardColSize){
    if ((board == NULL) || (boardSize == 0) || (boardColSize == NULL) || (*boardColSize == 0)) {
        return;
    }

    int i;
    int j;
    int **graph;
    graph = (int **)malloc(boardSize * sizeof(int *));
    for (i = 0; i < boardSize; i++) {
        graph[i] = (int *)malloc((*boardColSize) * sizeof(int));
        memset(graph[i], 0, (*boardColSize) * sizeof(int));
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            if (board[i][j] == 'X') {
                graph[i][j] = 1;
            } else {
                graph[i][j] = 0;
            }
        }
    }


    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            if ((i == 0) || (j == 0) || (i == boardSize - 1) || (j == *boardColSize - 1)) {
                SubFuncDFS(graph, boardSize, boardColSize, i, j);
            }
        }
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            if ((graph[i][j] == 1) || (graph[i][j] == 0)) {
                board[i][j] = 'X';
            } else {
                board[i][j] = 'O';
            }
        }
    }

    for (i = 0; i < boardSize; i++) {
        free(graph[i]);
    }
    free(graph);
}
```

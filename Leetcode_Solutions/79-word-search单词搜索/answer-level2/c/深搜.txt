### 解题思路
深搜，搜到结果则返回true；否则返回false继续搜其他路径
idx指向word当前位置，搜到strlen(word)是表示成功匹配到
visited里走过的节点（值为1）不能重复搜

### 代码

```c


bool backtrace(char** board, int size, int colSize, char* word, int idx, int i, int j, char *visited) {
    if (idx == strlen(word)) return true;

    if (i < 0 || i >= size || j < 0 || j >=colSize) return false;
    if (board[i][j] != word[idx]) return false;
    if (visited[i*colSize+j]) return false;

    visited[i*colSize+j] = 1;
    if (backtrace(board, size, colSize, word, idx+1, i+1, j, visited)) return true;
    if (backtrace(board, size, colSize, word, idx+1, i-1, j, visited)) return true;
    if (backtrace(board, size, colSize, word, idx+1, i, j+1, visited)) return true;
    if (backtrace(board, size, colSize, word, idx+1, i, j-1, visited)) return true;
    visited[i*colSize+j] = 0;

    return false;
}


bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if (!board || boardSize == 0 || !boardColSize || boardColSize[0] == 0 || !word) return false;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] != word[0]) continue;
            char visited[boardSize][boardColSize[0]];
            (void)memset(visited, 0, boardSize * boardColSize[0]);
            if (backtrace(board, boardSize, boardColSize[0], word, 0, i, j, visited)) return true;
        }
    }
    return false;
}
```
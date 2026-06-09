![image.png](https://pic.leetcode-cn.com/5b844f9b85f82c94196020fba6011e00e331165d8572b1f22c91d117008cd28f-image.png)
注意当前节点未找到的时候将访问节点置为未访问

```
bool core(char** board, int boardSize, int* boardColSize, char * word, int now, int** visited, int i, int j)
{
    if (i < 0 || i >= boardSize || j < 0 || j >= *boardColSize) {
        return false;
    }
    if (board[i][j] == word[now] && !visited[i][j]) {
        visited[i][j] = 1;
        if (now == strlen(word) - 1) {
            return true;
        } else {
            bool up = core(board, boardSize, boardColSize, word, now + 1, visited, i - 1, j);
            bool down = core(board, boardSize, boardColSize, word, now + 1, visited, i + 1, j);
            bool left = core(board, boardSize, boardColSize, word, now + 1, visited, i, j - 1);
            bool right = core(board, boardSize, boardColSize, word, now + 1, visited, i, j + 1);
            if (up || down || left || right) {
                return true;
            }
            visited[i][j] = 0; 
        }
    }
    return false;
}
bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
    if (word == NULL) {
        return false;
    }
    int** visited = (int**)malloc(sizeof(int*) * boardSize);
    for(int i = 0; i < boardSize; i++) {
        visited[i] = (int*)malloc(sizeof(int) * (*boardColSize));
        memset(visited[i], 0, sizeof(int) * (*boardColSize));

    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (board[i][j] == word[0]) {
                if (core(board, boardSize, boardColSize, word, 0, visited, i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}
```

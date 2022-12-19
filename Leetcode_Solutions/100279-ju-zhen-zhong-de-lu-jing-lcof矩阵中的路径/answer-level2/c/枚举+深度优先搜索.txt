[算法详解](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/)
```c
bool dfs(char** board, int boardSize, int* boardColSize, char* word, int index, int row, int col) {
    if (row < 0 || row == boardSize || col < 0 || col == *boardColSize || word[index] != board[row][col]) {
        return false;
    }

    if (index == strlen(word) - 1) return true;

    char temp = board[row][col];
    board[row][col] = '/';

    bool match = dfs(board, boardSize, boardColSize, word, index + 1, row + 0, col + 1) || 
                 dfs(board, boardSize, boardColSize, word, index + 1, row + 1, col + 0) || 
                 dfs(board, boardSize, boardColSize, word, index + 1, row + 0, col - 1) || 
                 dfs(board, boardSize, boardColSize, word, index + 1, row - 1, col + 0);

    board[row][col] = temp;
    return match;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < *boardColSize; ++j) {
            if (dfs(board, boardSize, boardColSize, word, 0, i, j)) return true;
        }
    }
    return false;
}
```

### 解题思路
此处撰写解题思路

### 代码

```c


char g_dir[][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
bool findword(char** board, int boardSize, int* boardColSize, char * word, int x, int y, int step)
{
    if (step == (strlen(word) - 1) && board[x][y] == word[step]) {
        return 1;
    }
    
    if (word[step] == board[x][y]) {  
        char c = board[x][y];    
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int m = x + g_dir[i][0];
            int n = y + g_dir[i][1];
            if (m >= 0 && n >= 0 && m < boardSize && n < boardColSize[0] && board[m][n] != '#') {
                bool temp = findword(board, boardSize, boardColSize, word, m, n, step + 1);
                if (temp) {
                    return 1;
                }
            }
        }

        board[x][y] = c;
    } 
    return 0;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
    bool isExist;

    if (strlen(word) == 0) {
        return 0;
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (word[0] == board[i][j]) {
                isExist = findword(board, boardSize, boardColSize, word, i, j, 0);
                if (isExist) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
```
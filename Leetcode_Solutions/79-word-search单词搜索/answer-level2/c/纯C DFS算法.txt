```
int g_boardSize;
int g_boardColSize;

void InitGlobalValue(int boardSize, int boardColSize)
{
    g_boardSize = boardSize;
    g_boardColSize = boardColSize;
}

bool Dfs(int vistCount, int x, int y, char **board, char *vist, char *word) 
{
    int newX;
    int newY;
    bool ret = false;

    if (board[y][x] != word[vistCount]) {
        return false;
    }

    *(vist + g_boardColSize * y + x) = 1;
    vistCount++;

    if (vistCount == strlen(word)) {
        return true;
    }

    /* 基于当前x,y 探索下一个节点,左->右->上->下 */ 
    if (x >= 1) { 
        newX = x - 1;
        newY = y;
        if (*(vist + g_boardColSize * newY + newX) != 1) {
            ret =  Dfs(vistCount, newX, newY, board, vist, word);
            if (ret == true) {
                return ret;
            }
        }
    } 

    if (x <= g_boardColSize - 2 && g_boardColSize >= 2) { // 2 至少保证大于两列，才能右移
        newX = x + 1;
        newY = y;
        if (*(vist + g_boardColSize * newY + newX) != 1) {
            ret =  Dfs(vistCount, newX, newY, board, vist, word);
            if (ret == true) {
                return ret;
            } 
        }
    }

    if (y >= 1) {
        newX = x;
        newY = y - 1;
        if (*(vist + g_boardColSize * newY + newX) != 1) {
            ret =  Dfs(vistCount, newX, newY, board, vist, word);
            if (ret == true) {
                return ret;
            } 
        }
    }

    if (y <= g_boardSize - 2 && g_boardSize >= 2) { // 2 至少保证大于两行，才能下移
        newX = x;
        newY = y + 1;
        if (*(vist + g_boardColSize * newY + newX) != 1) {
            ret =  Dfs(vistCount, newX, newY, board, vist, word);
            if (ret == true) {
                return ret;
            } 
        }
    }

    *(vist + g_boardColSize * y + x) = 0;
    
    return ret;
}

bool exist(char **board, int boardSize, int *boardColSize, char * word)
{
    int arrayCount;
    int x;
    int y;
    bool ret = false;
    char *vist = NULL;
 
    arrayCount = boardSize * (*boardColSize);
    if (arrayCount <= 0 || arrayCount < strlen(word) || strlen(word) == 0) {
        return false;
    }

    vist = (char *)malloc(sizeof(char) * arrayCount);
    if (vist == NULL) {
        return NULL;
    }
    (void)memset(vist, 0, sizeof(char) * arrayCount);

    InitGlobalValue(boardSize, *boardColSize);

    for (x = 0; x < *boardColSize; x++) {
        for (y = 0; y < boardSize; y++) {
            // 先找到第一个首字母符合的开始DFS
            if (board[y][x] != word[0]) {
                continue;
            }

            ret = Dfs(0, x, y, board, vist, word);
            if (ret == true) {
                free(vist);
                return ret;
            }

            (void)memset(vist, 0, sizeof(char) * arrayCount);
        }
    }

    free(vist);
    return ret;
}
```

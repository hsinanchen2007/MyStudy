### 解题思路
1、深度优先搜索；
2、每次搜索的路径上，记录已经搜索的节点，避免再次搜索到；
3、每次搜索后，清除搜索记录，防止干扰下次；

### 代码

```c

struct position {
    int rightPos;
    int downPos;
};

int hash[200][200];

int dsf(char** board, int boardSize, int boardColSize, struct position pos, char* word, int index)
{
    int i = pos.downPos;
    int j = pos.rightPos;
    if (*(word + index) == '\0') {
        return true;
    }

    if (j < 0 || j >= boardColSize || i < 0 || i >= boardSize) {
        return false;
    }
    if (hash[i][j] != 0) {
        return false;
    }
    if (board[i][j] == *(word + index)) {
        hash[i][j] = 1;
        pos.rightPos = j;
        pos.downPos = i - 1;
        if (dsf(board, boardSize, boardColSize, pos, word, index + 1) == true) {
            return true;
        }
        pos.rightPos = j;
        pos.downPos = i + 1;
        if (dsf(board, boardSize, boardColSize, pos, word, index + 1) == true) {
            return true;
        }
        pos.rightPos = j - 1;
        pos.downPos = i;
        if (dsf(board, boardSize, boardColSize, pos, word, index + 1) == true) {
            return true;
        }
        pos.rightPos = j + 1;
        pos.downPos = i;
        if (dsf(board, boardSize, boardColSize, pos, word, index + 1) == true) {
            return true;
        }
        hash[i][j] = 0;
    }
    return false;
}

void resetHash()
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 200; i++) {
        for (j = 0; j < 200; j++) {
            hash[i][j] = 0;
        }
    }
    return;
}
bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int i = 0;
    int j = 0;
    struct position pos;

    resetHash();

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == *word) {
                hash[i][j] = 1;
                pos.rightPos = j;
                pos.downPos = i - 1;
                if (dsf(board, boardSize, boardColSize[0], pos, word, 1) == true) {
                    return true;
                }

                pos.rightPos = j;
                pos.downPos = i + 1;
                if (dsf(board, boardSize, boardColSize[0], pos, word, 1) == true) {
                    return true;
                }

                pos.downPos = i;
                pos.rightPos = j - 1;
                if (dsf(board, boardSize, boardColSize[0], pos, word, 1) == true) {
                    return true;
                }

                pos.downPos = i;
                pos.rightPos = j + 1;
                if (dsf(board, boardSize, boardColSize[0], pos, word, 1) == true) {
                    return true;
                }
                hash[i][j] = 0;
            }
        }
    }

    return false;
}
```
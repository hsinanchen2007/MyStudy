### 解题思路
简单易懂，先建立Direction数组，标识一个位置四周的8个其他位置
写个子函数，用来计算周围8个位置中有效位置（8个位置中某些位置可能超出边界）中的live和dead情况，并输出当前位置的应有状态
循环计算原有board中各个点的新状态，并记录到一个单独的数组中，最后把数组中的内容拷贝到元数组board中。

没有考虑在原有空间上直接修改，有个大概的想法，就是计算的新值，可以放到原数组中，但是需要能分辨出这个新值对应的原值是多少，
可以考虑用状态map表来实现，整个计算过程中都是用map表中的中间状态来表示，最后再根据这个中间值换成最终值。

### 代码

```c
struct Direction {
    int x;
    int y;
};

struct Direction directions[8] = {
    {-1, -1},
    {0, -1},
    {1, -1},
    {-1, 0},
    {1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
};

int GetPointStatus(int x, int y, int** board, int boardSize, int* boardColSize) {
    int liveNum = 0;
    int deadNum = 0;
    int newX = 0;
    int newY = 0;
    for (int i = 0; i < 8; i++) {
        newX = x + directions[i].x;
        newY = y + directions[i].y;
        
        if (newX >= 0 && newX < boardSize && newY >= 0 && newY < boardColSize[0]) {
            printf("newX[%d] :: newY[%d]\n", newX, newY);
            if (board[newX][newY] == 1) {
                liveNum++;
            } else if (board[newX][newY] == 0) {
                deadNum++;
            }
        }
    }

    int ret = 0;
    if (board[x][y] == 1) {
        if (liveNum < 2) {
            ret = 0;
        } else if (liveNum == 2 || liveNum == 3) {
            ret = 1;
        } else if (liveNum > 3) {
            ret = 0;
        }
    } else {
        if (liveNum == 3) {
            ret = 1;
        }
    }

    return ret;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize <=0 || boardColSize == NULL || boardColSize[0] <= 0) {
        return;
    }

    printf("boardSize[%d]   boardColSize[%d] \n", boardSize, boardColSize[0]);

    int *newBoard = (int *)calloc(boardSize * boardColSize[0], sizeof(int));

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            newBoard[i * boardColSize[0] + j] = GetPointStatus(i, j, board, boardSize, boardColSize);
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            board[i][j] = newBoard[i * boardColSize[0] + j];
        }
    }

    return;
}
```
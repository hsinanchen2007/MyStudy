### 解题思路
1.先找出R的位置
2.然后4个方向遍历，并进行判断

### 代码

```c

bool IsInArea(int x, int y, int size)
{
    return x >= 0 && x < size && y >= 0 && y < size;
}

int AREA[4][2] = {{0, 1},
                  {1, 0},
                  {0, -1},
                  {-1, 0}};

int numRookCaptures(char** board, int boardSize, int* boardColSize)
{
    if (board == NULL || boardSize == 0 || boardColSize == NULL) {
        return 0;
    }

    int result = 0;
    // 1.找出R的位置
    int xOfR = 0;
    int yOfR = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == 'R') {
               xOfR = i;
               yOfR = j;
               break;
            }
        }
    }

    // 2.4个方向遍历
    for (int i = 0; i < 4; i++) {
        int newX = xOfR + AREA[i][0];
        int newY = yOfR + AREA[i][1];

        while (IsInArea(newX, newY, boardSize)) {
            if (board[newX][newY] == 'p') {
                result = result + 1;
                break;
            }

            if (board[newX][newY] == 'B') {
                break;
            }

            newX = newX + AREA[i][0];
            newY = newY + AREA[i][1];
        }
    }
    return result;
}
```
1、首先筛选出新鲜的橘子，只有新鲜的橘子才会被腐蚀；
2、在筛选新鲜橘子后，同时也会得出当前是否当前是否都是腐蚀了的橘子，是的话就返回0；
3、开始腐蚀橘子，并每分钟的记录，如果某一分钟没有被腐蚀，则退出即可；
4、退出后如果还有没有被腐蚀的橘子，那么返回-1，否则返回round - 1。

```
#define ALREADY_ROTTED 1
#define STILL_FRESH 0

bool willRotted(int** grid, int x, int y, int xMax , int yMax)
{
    if (x - 1 >= 0) {
        if (grid[x - 1][y] == 2) {
            return true;
        }
    }

    if (x + 1 < xMax) {
        if (grid[x + 1][y] == 2) {
            return true;
        }
    }

    if (y - 1 >= 0) {
        if (grid[x][y - 1] == 2) {
            return true;
        }
    }

    if (y + 1 < yMax) {
        if (grid[x][y + 1] == 2) {
            return true;
        }
    }

    return false;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int minMins = 0;
    int empty = 0;
    int fresh = 0;
    int rotted = 0;
    int i = 0;
    int j = 0;
    int data[1024][3];
    int tRotted = 0;
    int totalRotted = 0;
    int round = 0;

    /* 过滤特殊情形 */
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < (*gridColSize); j++) {
            if (grid[i][j] == 0) {
                empty++;
            } else if (grid[i][j] == 1) {
                data[fresh][0] = i;
                data[fresh][1] = j;
                data[fresh][2] = STILL_FRESH;
                fresh++;
            } else {
                rotted++;
            }
        }
    }
    /* 已经腐蚀完了的 */
    if (rotted != 0 && fresh == 0) {
        return 0;
    }

    /* 计算 */
    while (true) {
        tRotted = 0;
        for (i = 0; i < fresh; i++) {
            if (willRotted(grid, data[i][0], data[i][1], gridSize, (*gridColSize)) == true && data[i][2] == STILL_FRESH) {
                data[i][2] = ALREADY_ROTTED;
                tRotted++;
            }
        }
        totalRotted += tRotted;
        for (i = 0; i < fresh; i++) {
            if (data[i][2] == ALREADY_ROTTED) {
                grid[data[i][0]][data[i][1]] = 2;
            }
        }
        round++;
        if (tRotted == 0) {
            break;
        }
    }
    
    if (totalRotted < fresh) {
        return -1;
    }
    
    return round - 1;
}
```

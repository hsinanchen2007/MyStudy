### 解题思路
遍历海洋，计算离他最近的陆地的距离。最后返回其中的最大值。
遍历海洋：
    指定一块海洋，往他的周围一步一步检查，找到第一块陆地，计算距离，就是离他最近的陆地的距离。
    然后相同方法处理下一块海洋。
或者遍历陆地：【SELECTED】
    指定一块陆地，一步一步的检查。如果是海洋，则更新此海洋到陆地的最小距离。如果已超过最小距离，则不必继续检查该海洋附近的海域。直到找不到海洋，则检查结束。
    然后相同方法处理下一块陆地。
    最后遍历海洋，找到最小距离最大的哪块海洋。

### 执行结果
执行用时 :196 ms, 在所有 C 提交中击败了27.11%的用户
内存消耗 :10 MB, 在所有 C 提交中击败了42.22%的用户

### 代码
```c

typedef struct tagPOS_S {
    int x;
    int y;
    int dist;
}POS_S;

int GetSeaCnt(int** grid, int gridSize, int* gridColSize){
    int i,j,cnt = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0) {
                cnt++;
            }
        }
    }

    return cnt;
}

void initSeaInfo(int** grid, int gridSize, int* gridColSize, int *sea, int seaCnt) {
    int i, j, n = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0 && n < seaCnt) {
                sea[i * gridSize + j] = -1;
                n++;
            }
        }
    }

    return;
}

int g_MaxDis = -1;
int g_x = -1;
int g_y = -1;

void bfs(int** grid, int gridSize, int* gridColSize, POS_S *curPos, int curCnt, int *sea, POS_S *nextPos) {

    /* 查找一步范围内的海域，更新他们的dist */
    int i, j, c;
    int dDist[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dX, dY, x, y;
    int nextCnt = 0;
    //printf("....curCnt = %d \n", curCnt);
    for (c = 0; c < curCnt; c++) {
        for (i = 0; i < 4; i++) {
            int curDist = curPos[c].dist + 1;
            dX = dDist[i][0];
            dY = dDist[i][1];
            x = curPos[c].x;
            y = curPos[c].y;
            if (!((0 <= x + dX && x + dX <= gridSize -1) && (0 <= y + dY && y + dY <= gridColSize[x + dX] - 1))) {
                continue;
            }
            //printf("%d %d\n", x + dX, y + dY);
            if (grid[x + dX][y + dY] == 1) {
                continue;
            }

            if (sea[(x + dX) * gridSize + (y + dY)] == -1 || sea[(x + dX) * gridSize + (y + dY)] > curDist) {
                sea[(x + dX) * gridSize + (y + dY)] = curDist;
            } else {
                continue;
            }

            nextPos[nextCnt].x = x + dX;
            nextPos[nextCnt].y = y + dY;
            nextPos[nextCnt].dist = curDist;
            nextCnt++;
            //printf("nextCnt = %d \n", nextCnt);
        }
    }
    
    if (nextCnt == 0) {
        return;
    }
    //printf("bfs\n");
    /* 如果存在一步范围内的海域，则再扩散一步继续查找 */
    bfs(grid, gridSize, gridColSize, nextPos, nextCnt, sea, curPos);

    return;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return -1;
    }

    if (gridSize == 1) {
        return -1;
    }
    
    int seaCnt = GetSeaCnt(grid, gridSize, gridColSize);
    if (seaCnt == 0 || seaCnt == gridSize * gridColSize[gridSize - 1]) {
        return -1;
    }

    /* 所有的海洋用数组存一下：坐标、最小距离 */
    int *sea = (int *)malloc(sizeof(int) * gridSize * gridColSize[gridSize - 1]);
    if (sea == NULL) {
        return -1;
    }
    initSeaInfo(grid, gridSize, gridColSize, sea, gridSize * gridColSize[gridSize - 1]);

    /* 遍历找陆地，然后BFS方法更新附近海洋距离陆地的最小距离。更新最小距离最大的海洋坐标。 */
    int i,j, curCnt, nextCnt;
    POS_S *curLand = (POS_S *)malloc(sizeof(POS_S) * gridSize * gridColSize[gridSize - 1]);
    if (curLand == NULL) {
        free(sea);
        return -1;
    }

    POS_S *nextLand = (POS_S *)malloc(sizeof(POS_S) * gridSize * gridColSize[gridSize - 1]);
    if (nextLand == NULL) {
        free(sea);
        free(curLand);
        return -1;
    }
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                curLand[0].x = i;
                curLand[0].y = j;
                curLand[0].dist = 0;
                curCnt = 1;
                bfs(grid, gridSize, gridColSize, curLand, curCnt, sea, nextLand);
            }
        }
    }

    int maxDist = -1;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 0) { 
                maxDist = maxDist >= sea[i * gridSize + j] ? maxDist : sea[i * gridSize + j];
            }
        }
    }

    free(nextLand);
    free(curLand);
    free(sea);
    
    return maxDist;
}
```
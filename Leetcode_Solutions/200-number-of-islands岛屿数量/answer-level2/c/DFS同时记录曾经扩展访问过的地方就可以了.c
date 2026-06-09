
遍历整个地图，如果没有访问过，并且是陆地，岛屿数量增加1，同时开始DFS进行扩展访问（碰到地图边界、已经访问过、碰到水域都需要停止），同时标记访问过的地方，将此岛屿所有的地域都置为访问过。
```
#define HAS_VISITED_FLAG 1
#define IS_LAND  1
#define MAX_DIRECT_NUM 4

typedef struct {
    int x;
    int y;
}POS;

void DFS(char** grid, int gridSize, int gridColSize, POS *curPos, char *visited)
{
    int i;
    int dxi[MAX_DIRECT_NUM] = {0, 1, 0, -1};
    int dyi[MAX_DIRECT_NUM] = {1, 0, -1, 0};
    POS nextPos;
        
    /* 超出范围就终止 */
    if ((curPos->x < 0) || (curPos->x >= gridSize) ||
        (curPos->y < 0) || (curPos->y >= gridColSize)) {
        return;
    } 
    
    /* 已经访问过就终止 */
    if (visited[curPos->x * gridColSize + curPos->y] == HAS_VISITED_FLAG) {
        return;
    }
    
    /* 碰到水就终止 */
    if (grid[curPos->x][curPos->y] - '0' == 0) {
        return;
    }
    
    /* 置当前节点访问过，并向四周扩展访问 */
    visited[curPos->x * gridColSize + curPos->y] = HAS_VISITED_FLAG;
    for (i = 0; i < MAX_DIRECT_NUM; i++) {
        nextPos.x = curPos->x + dxi[i];
        nextPos.y = curPos->y + dyi[i];
        DFS(grid, gridSize, gridColSize, &nextPos, visited);
    }
    
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int i;
    int j;
    int isLandCnt = 0;
    POS curPos;
    char *visited = NULL;
    
    if ((grid == NULL) || (gridColSize == NULL)) {
        return 0;
    }
    
    if ((gridSize == 0) || (*gridColSize == 0)) {
        return 0;
    }
    
    visited = (char *)malloc(gridSize * (*gridColSize) * sizeof(char));
    if (visited == NULL) {
        return 0;
    }
    
    memset(visited, 0, gridSize * (*gridColSize) * sizeof(char));
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if ((visited[i * (*gridColSize) + j] != HAS_VISITED_FLAG) &&
                (grid[i][j] - '0' == IS_LAND)) {
                isLandCnt++;
                curPos.x = i;
                curPos.y = j;
                DFS(grid, gridSize, *gridColSize, &curPos, visited);
            }
        }
    }
    
    free(visited);
    
    return isLandCnt;
}
```

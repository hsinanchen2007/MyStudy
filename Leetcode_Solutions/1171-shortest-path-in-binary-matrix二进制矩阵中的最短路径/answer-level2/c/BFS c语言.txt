#define QUE_MAX 10000

#define PUSH_QUE(grid, que, dep, x, y, dist) \
do { \
    (que)[(dep)][0] = (x); \
    (que)[(dep)++][1] = (y); \
    (grid)[x][y] = dist + 1; \
} while (0)

#define POP_QUE(que, pos, x, y) \
do { \
    (x) = (que)[(pos)][0]; \
    (y) = (que)[(pos)++][1]; \
} while (0)

void GridFind(int **grid, int x, int y, int n, int dist, unsigned char que[QUE_MAX][2], int *dep) {
    /* 上 */
    if ((x > 0) && (grid[x - 1][y] == 0)) {
        PUSH_QUE(grid, que, *dep, x - 1, y, dist);
    }
    /* 下 */
    if ((x < n) && (grid[x + 1][y] == 0)) {
        PUSH_QUE(grid, que, *dep, x + 1, y, dist);
    }
    /* 左 */
    if ((y > 0) && (grid[x][y - 1] == 0)) {
        PUSH_QUE(grid, que, *dep, x, y - 1, dist);
    }
    /* 右 */
    if ((y < n) && (grid[x][y + 1] == 0)) {
        PUSH_QUE(grid, que, *dep, x, y + 1, dist);
    }
    
    /* 左上 */
    if ((x > 0) && (y > 0) && (grid[x - 1][y - 1] == 0)) {
        PUSH_QUE(grid, que, *dep, x - 1, y - 1, dist);
    }
    /* 左下 */
    if ((x < n) && (y > 0) && (grid[x + 1][y - 1] == 0)) {
        PUSH_QUE(grid, que, *dep, x + 1, y - 1, dist);
    }
    /* 右上 */
    if ((x > 0) && (y < n) && (grid[x - 1][y + 1] == 0)) {
        PUSH_QUE(grid, que, *dep, x - 1, y + 1, dist);
    }
    /* 右下 */
    if ((x < n) && (y < n) && (grid[x + 1][y + 1] == 0)) {
        PUSH_QUE(grid, que, *dep, x + 1, y + 1, dist);
    }
    return;
}

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
    unsigned char que[QUE_MAX][2] = {0};
    int x = 0, y = 0;
    int dep = 0, pos = 0, dist = 1;
    //printf("gridSize=%d *gridColSize=%d\n", gridSize, *gridColSize);
    //printf("grid[n-1][n-1]=%d\n", grid[gridSize - 1][gridSize - 1]);
    
    if ((grid[0][0] == 1) || (grid[gridSize - 1][*gridColSize - 1] == 1)) {
        return -1;
    }
    
    if ((gridSize == 1) && (*gridColSize == 1) && (grid[gridSize - 1][*gridColSize - 1] == 1)) {
        return -1;
    }
    
    if ((gridSize == 1) && (*gridColSize == 1) && (grid[gridSize - 1][*gridColSize - 1] == 0)) {
        return 1;
    }
    
    PUSH_QUE(grid, que, dep, 0, 0, dist);
    while (pos != dep) {
        for (int i = dep - pos; i > 0; i--) {
            POP_QUE(que, pos, x, y);
            GridFind(grid, x, y, gridSize - 1, dist, que, &dep);
        }
        dist++;
    }
    
    dist = grid[gridSize - 1][*gridColSize - 1];
    if ((dist == 0) || (dist == 1)) {
        dist = -1;
    }

    return dist;
}
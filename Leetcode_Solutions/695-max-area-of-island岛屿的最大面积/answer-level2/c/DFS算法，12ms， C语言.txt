DFS算法简单易懂，直接上代码：

#define MAX_DIRCTION    4
#define MAX_GRID        50

int g_incrX[MAX_DIRCTION] = {-1, 1, 0, 0};
int g_incrY[MAX_DIRCTION] = {0, 0, -1, 1};
int g_area = 0;

void CalIslandArea(int** grid, int gridSize, int colSize, int x, int y)
{
    int nextX, nextY, directIdx;

    g_area++;
    grid[x][y] = 2;
    //printf("%d, %d;\n", x, y);

    for (directIdx = 0; directIdx < MAX_DIRCTION; directIdx++) {
        nextX = x + g_incrX[directIdx];
        nextY = y + g_incrY[directIdx];

        if (nextX < 0 || nextY < 0 || nextX >= gridSize || nextY >= colSize || grid[nextX][nextY] != 1) {
            continue;
        }

        CalIslandArea(grid, gridSize, colSize, nextX, nextY);
    }
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i, j, colSize;
    int maxArea = 0;

    if (grid == NULL || gridSize < 1 || gridSize > MAX_GRID || gridColSize == NULL) {
        return 0;
    }
    
    colSize = gridColSize[0];

    if (colSize < 1 || colSize > MAX_GRID) {
        return 0;
    }
    
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < colSize; j++) {
            if (grid[i][j] == 1) {
                g_area = 0;
                CalIslandArea(grid, gridSize, colSize, i, j);
                //printf("area = %d;\n", g_area);

                if (maxArea < g_area) {
                    maxArea = g_area;
                }
            }
        }
    }
    
    return maxArea;
}
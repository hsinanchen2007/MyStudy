### 解题思路
此处撰写解题思路

### 代码

```c
#define FALSE     0
#define TRUE      1
#define VISITED   3
#define UNVISITED 0
#define END_FLAG  2

int g_gridSize;
int g_gridColSize;
int g_zeroNum;

/* 利用BFS搜索有效的路径个数，返回值为是否找到有效路径的标志findFlg，初始化findFlg为FALSE，当找到有效路径时，findFlg置为TRUE */
void Bfs(int** grid, int row, int col, int* pathNum, int* findFlg, int* curZeroNum)
{
    /* 判断当前位置是否有效，无效时返回 */
    if ((row < 0) || (row >= g_gridSize) || (col < 0) || (col >= g_gridColSize) || (grid[row][col] == -1) || (grid[row][col] == VISITED)) {
        return;
    }
    //printf("row:%d; col:%d\n", row, col);
    /* 搜索的终止条件：到达结束方格，且每一个无障碍方格都通过一次 */
    if (grid[row][col] == END_FLAG) {
        if (*curZeroNum == (g_zeroNum + 1)) {
            *findFlg = TRUE;
            *pathNum += 1;
            //printf("pathNuml:%d\n", *pathNum);
            return;
        } else {
            return;
        }
    }

    /* 如果当前位置为障碍物，则返回 */
    //printf("start:\n");
    /* 当前位置标记为visited，curZeroNum加1 */
    grid[row][col] = VISITED;
    *curZeroNum += 1;

    /* 开始进行搜索 */
    Bfs(grid, row - 1, col, pathNum, findFlg, curZeroNum); // 向上搜索
    Bfs(grid, row, col + 1, pathNum, findFlg, curZeroNum); // 向右搜索
    Bfs(grid, row + 1, col, pathNum, findFlg, curZeroNum); // 向下搜索
    Bfs(grid, row , col - 1, pathNum, findFlg, curZeroNum); // 向左搜索
    
    /* 恢复现场 */
    grid[row][col] = UNVISITED;
    *curZeroNum -= 1;
    //printf("end:\n");
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize){
    if ((grid == NULL) || (gridSize == 0) || (*gridColSize == 0)) {
        return 0;
    }
    int startRow, startCol;
    int zeroNum    = 0;
    int pathNum    = 0;
    int findFlg    = FALSE;
    int curZeroNum = 0;

    g_gridSize    = gridSize;
    g_gridColSize = *gridColSize;
    /* 遍历网格，找到起始坐标，并统计网格中无障碍方格的个数 */
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 0) {
                zeroNum++;
            } else if (grid[i][j] == 1) {
                startRow = i;
                startCol = j;
            }
        }
    }
    g_zeroNum = zeroNum;

    Bfs(grid, startRow, startCol, &pathNum, &findFlg, &curZeroNum);

    if (findFlg == TRUE) {
        return pathNum;
    } else {
        return 0;
    }
}
```
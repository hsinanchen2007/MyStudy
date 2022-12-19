### 解题思路
深度优先搜索
找到1个土地，然后向四周查找。
找到之后标记为找到。在当前数据中操作，预留后续还原。
### 代码

```c
#define MAXSIZE 50
#define MAX(a, b) ((a > b) ? a : b)
#define WATER 0
#define ISLAND 1
#define VISISLAND 2
#define PRINTF // printf

typedef struct stArea{
    int** grid;
    int row;
    int col;
    int curRow;
    int curCol;
}STAREA;
void DfsMaxArea(STAREA *pArea, int *pCurNum)
{
    PRINTF("%d %d %d %d\n",pArea->curRow, pArea->row, pArea->curCol, pArea->col);
    if ((pArea->curRow < 0) || (pArea->curRow >= pArea->row)) {
        return;
    }
    if ((pArea->curCol < 0) || (pArea->curCol >= pArea->col)) {
        return;
    }
    if ((pArea->grid[pArea->curRow][pArea->curCol] == WATER) ||
        (pArea->grid[pArea->curRow][pArea->curCol] == VISISLAND)) {
        return;
    }
    if (pArea->grid[pArea->curRow][pArea->curCol] == ISLAND){
        PRINTF("%d %d %d\n",pArea->curRow, pArea->curCol, *pCurNum);
        (*pCurNum)++;
        pArea->grid[pArea->curRow][pArea->curCol] = VISISLAND; // 更新为已访问
        int tmpRow = pArea->curRow;
        int tmpCol = pArea->curCol;
        pArea->curRow = tmpRow;
        pArea->curCol = (tmpCol - 1);
        DfsMaxArea(pArea, pCurNum);
        pArea->curRow = (tmpRow - 1);
        pArea->curCol = tmpCol;
        DfsMaxArea(pArea, pCurNum);
        pArea->curRow = tmpRow;
        pArea->curCol = (tmpCol + 1);
        DfsMaxArea(pArea, pCurNum);
        pArea->curRow = (tmpRow + 1);
        pArea->curCol = tmpCol;
        DfsMaxArea(pArea, pCurNum);
    }
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int iRetMaxArea = 0;
    if ((grid == NULL)||(gridColSize == NULL)) {
        goto END;
    }
    STAREA pArea = {grid, gridSize, *gridColSize, 0, 0};
    int curMaxArea = 0;
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < (*gridColSize); j++) {
            if (grid[i][j] == ISLAND) {
                pArea.curRow = i;
                pArea.curCol = j;
                curMaxArea = 0;
                DfsMaxArea(&pArea, &curMaxArea);
                iRetMaxArea = MAX(iRetMaxArea, curMaxArea);
             }

        }
    }
END:
    return iRetMaxArea;
}
```
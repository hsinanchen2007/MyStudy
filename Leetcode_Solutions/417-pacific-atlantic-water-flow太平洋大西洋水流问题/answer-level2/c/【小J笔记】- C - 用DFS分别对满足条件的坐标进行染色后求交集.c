- i == 0 j == 0 染色能到达太平洋的点
- i == matRow - 1 j == matCol - 1染色能到达大西洋的点
- 注意只需要染色即可，不需要回溯，所以DFS必然可以结束
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE (160)
#define TRUE (1)
#define FALSE (0)
#define NULL_PTR (0)

int g_west[MAX_SIZE][MAX_SIZE];
int g_east[MAX_SIZE][MAX_SIZE];
int g_matRow;
int g_matCol;

int g_dir[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

int IsValidCrood(int row, int col)
{
    if ((row < 0) || (row > g_matRow)) {
        return FALSE;
    }
    if ((col < 0) || (col > g_matCol)) {
        return FALSE;
    }
    return TRUE;
}

void Dfs(int** matrix, int row, int col, int flag[MAX_SIZE][MAX_SIZE])
{
    int i;
    int sonRow;
    int sonCol;
    flag[row][col] = TRUE;
    for (i = 0; i < 4; i++) {
        sonRow = row + g_dir[i][0];
        sonCol = col + g_dir[i][1];
        if ((IsValidCrood(sonRow, sonCol) == TRUE) && 
            (flag[sonRow][sonCol] == FALSE) && 
            (matrix[sonRow][sonCol] >= matrix[row][col])) {
                Dfs(matrix, sonRow, sonCol, flag);
        }
    }
}

int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    int i;
    int j;    
    int **ret;
    int maxRet;
    int index = 0;
    if ((matrix == NULL_PTR) || (matrixColSize == NULL_PTR)) {
        *returnSize = 0;
        return NULL_PTR;
    }
    if ((matrixSize == 0) || (matrixColSize[0] == 0)) {
        *returnSize = 0;
        return NULL_PTR;
    }
    g_matRow = matrixSize - 1;
    g_matCol = matrixColSize[0] - 1;
    maxRet = matrixSize * matrixColSize[0];
    ret = (int**)malloc(sizeof(int*) * maxRet);
    for (i = 0; i < maxRet; i++) {
        ret[i] = (int*)malloc(sizeof(int) * 2);
    }
    for (i = 0; i <= g_matRow; i++) {
        for (j = 0; j <= g_matCol; j++) {
            g_west[i][j] = FALSE;
            g_east[i][j] = FALSE;            
        }
    }
    for (i = 0; i <= g_matRow; i++) {
        for (j = 0; j <= g_matCol; j++) {
            if ((i == 0) || (j == 0)) {
                Dfs(matrix, i, j, g_west);
            }          
            if ((i == g_matRow) || (j == g_matCol)) {
                Dfs(matrix, i, j, g_east);
            }
        }
    }
    for (i = 0; i <= g_matRow; i++) {
        for (j = 0; j <= g_matCol; j++) {
            if ((g_west[i][j] == TRUE) && (g_east[i][j] == TRUE)) {
                ret[index][0] = i;
                ret[index][1] = j;
                index++;
            }
        }
    }

    *returnSize = index;
    *returnColumnSizes = (int*)malloc(sizeof(int) * index);
    for (i = 0; i < index ; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return ret;
}
```

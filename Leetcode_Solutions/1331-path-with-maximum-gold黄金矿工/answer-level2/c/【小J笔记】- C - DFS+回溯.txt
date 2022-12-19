- 基本的回溯算法，没想到什么好的剪枝方法。
- 由于递归必然会结束，所以不需要结束条件，每次取最大值即可。
```
#define NULL_PTR (0)
#define TRUE (1)
#define FALSE (0)
#define MAX_SIZE (16)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int g_matRow;
int g_matCol;
int g_visit[MAX_SIZE][MAX_SIZE];
int g_val;

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

void InitVisit()
{
    int i,j;
    for (i = 0; i <= g_matRow; i++) {
        for (j = 0; j <= g_matCol; j++) {
            g_visit[i][j] = FALSE;            
        }
    }
}

void Dfs(int** grid, int row, int col, int val)
{
    int i;
    int sonRow;
    int sonCol;  
    g_val = MAX(g_val, val);
    for (i = 0; i < 4; i++) {
        sonRow = row + g_dir[i][0];
        sonCol = col + g_dir[i][1];
        if ((IsValidCrood(sonRow, sonCol) == TRUE) && 
            (g_visit[sonRow][sonCol] == FALSE) && 
            (grid[sonRow][sonCol] != 0)) {
            g_visit[sonRow][sonCol] = TRUE;
            Dfs(grid, sonRow, sonCol, val + grid[sonRow][sonCol]);
            g_visit[sonRow][sonCol] = FALSE;
        }
    }
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize)
{
    int i;
    int j;
    int val;
    if ((grid == NULL_PTR) || (gridColSize == NULL_PTR)) {
        return 0;
    }    
    if ((gridSize == 0) || (gridColSize[0] == 0)) {
        return 0;
    }    
    g_matRow = gridSize - 1;
    g_matCol = gridColSize[0] - 1;
    g_val = -1;
    for (i = 0; i <= g_matRow; i++) {
        for (j = 0; j <= g_matCol; j++) {
            if (grid[i][j] != 0) {  
                InitVisit();  
                val = grid[i][j];            
                g_visit[i][j] = TRUE;               
                Dfs(grid, i, j, val);
                g_visit[i][j] = FALSE;
            }
        }
    }    
    return g_val;
}
```

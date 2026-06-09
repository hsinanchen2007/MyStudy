### 解题思路
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

 

示例 1：



输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4



### 代码

```c
#if 0
//暴力法，  太慢
bool expand(int** grid, int gridSize, int* gridColSize, int i, int j){
    bool res = false;

    if (grid[i][j] != 2)
        return false;
    if (i > 0 && grid[i-1][j] == 1) {
        grid[i-1][j] = 2;
        res =  true;
    }
    if (j > 0 && grid[i][j-1] == 1) {
        grid[i][j-1] = 2;
        res = true;
    }
    if (i < gridSize - 1 && grid[i+1][j] == 1) {
        grid[i+1][j] = 2;
        res = true;
    }
    if (j < gridColSize[i] - 1 && grid[i][j+1] == 1) {
        grid[i][j+1] = 2;
        res  = true;
    }
    return res;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int minute = 0, i, j, m, n;
    bool expanded = true;
    int set[100][2] = {0};

    while (expanded) {
        expanded = false;
        m = 0;
        for (i = 0; i < gridSize; i++) {
            for(j = 0; j < gridColSize[i]; j++){
                if (grid[i][j] == 2){
                    set[m][0] = i;
                    set[m++][1] = j; 
                }
            }
        }

        for (i = 0; i < m; i++){
            if (expand(grid, gridSize, gridColSize, set[i][0], set[i][1]))
                expanded = true;
        }

        if(expanded)
            minute++;
    }

    for (i = 0; i < gridSize; i++) {
        for(j = 0; j < gridColSize[i]; j++){
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return minute;
}
#else

// 广度优先搜索
typedef struct{
    int row;
    int col;
}BadOrg;

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int r=0, w = 0, len, i, j, minute = -1;
    BadOrg q[10000] = {0};

    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[0]; j++){
            if(grid[i][j] == 2){
                q[w].row = i;
                q[w++].col = j;
            }
        }
    }

    while(r < w) {
        len = w - r;
        minute++;
        //printf("len=%d w=%d,r=%d\n",len,w,r);
        while(len--) {
            BadOrg * bad = &q[r++];
            //printf("badrow=%d badcol=%d\n",bad->row, bad->col);
            //printf("w=%d r=%d bad[%d][%d]=%d\n",w, r, bad->row, bad->col, grid[bad->row][bad->col]);
           
            if (bad->row > 0 && grid[bad->row - 1][bad->col] == 1){
                grid[bad->row - 1][bad->col] = 2;   //加入队列时就需要改成腐烂，否则会重复添加队列
                q[w].row = bad->row - 1;
                q[w++].col = bad->col;
            }
           
            if (bad->row < gridSize - 1 && grid[bad->row + 1][bad->col] == 1){
                grid[bad->row+1][bad->col] = 2;
                q[w].row = bad->row + 1;
                q[w++].col = bad->col;
            }
            
            if (bad->col > 0 && grid[bad->row][bad->col - 1] == 1){
                grid[bad->row][bad->col-1] = 2;
                q[w].row = bad->row;
                q[w++].col = bad->col - 1;
            }
             if (bad->col < gridColSize[0] - 1 && grid[bad->row][bad->col + 1] == 1){
                grid[bad->row][bad->col+1] = 2;
                q[w].row = bad->row;
                q[w++].col = bad->col + 1;
            }
        }
    }

    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[0]; j++){
            if(grid[i][j] == 1)
                return -1;
        }
    }

    return minute < 0 ? 0 : minute;
}
#endif
```
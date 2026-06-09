### 解题思路
1、深度搜索，一条路走到底，看是否可以走通；走通表示找到一条，走不通回来继续；
2、走通通过判断0的点已经走完，且走到了终点；
3、走过回来的时候，清除这次走的记录（节点是0的个数，走过的记录），不影响下次；
4、走过就标记下，节点的0个数减一；


### 代码

```c

#define POINT_START 1
#define POINT_END 2
#define POINT_PASS 0
#define POINT_STOP -1

int path_num = 0;
int map[20][20] = {0};
int zero_num = 0;

void dsf(int** grid, int gridSize, int gridColSize, int rowIndex, int colIndex)
{
    if (rowIndex < 0 || rowIndex > gridSize - 1 || colIndex < 0 || colIndex > gridColSize - 1) {
        return;
    }
    if (grid[rowIndex][colIndex] == POINT_STOP) {
        return;
    }
    if (map[rowIndex][colIndex] == 1) {
        return;
    }
    if (grid[rowIndex][colIndex] == POINT_END) {
        if (zero_num == 0) {
            path_num++;
        }
        return;
    }
    map[rowIndex][colIndex] = 1;
    if (grid[rowIndex][colIndex] == 0) {
        zero_num--;
    }

    dsf(grid, gridSize, gridColSize, rowIndex - 1, colIndex);
    dsf(grid, gridSize, gridColSize, rowIndex, colIndex - 1);
    dsf(grid, gridSize, gridColSize, rowIndex + 1, colIndex);
    dsf(grid, gridSize, gridColSize, rowIndex, colIndex + 1);

    map[rowIndex][colIndex] = 0;
    zero_num++;

    return;
}
int uniquePathsIII(int** grid, int gridSize, int* gridColSize){
    int i = 0;
    int j = 0;
    int start_row = 0, start_col = 0;
    path_num = 0;
    memset(map, 0, sizeof(int) * 20 * 20);
    zero_num = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if(grid[i][j] == 0) {
                zero_num++;
            } else if (grid[i][j] == POINT_START) {
                start_row = i;
                start_col = j;
            }
        }
    }
    dsf(grid, gridSize, gridColSize[0], start_row, start_col);
    return path_num;
}
```
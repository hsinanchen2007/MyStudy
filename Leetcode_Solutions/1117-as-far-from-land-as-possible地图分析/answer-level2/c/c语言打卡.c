### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int i, j, **memorize = (int**)malloc(gridSize * sizeof(int*));
    for(i = 0;i < gridSize;i ++)
        memorize[i] = (int*)calloc(gridColSize[i], sizeof(int));
    // 从左上开始，从左往右，从上往下
    for(i = 0;i < gridSize;i ++)
        for(j = 0;j < gridColSize[i];j ++)
            if(grid[i][j] == 1)
                memorize[i][j] = 0;
            else if(i == 0 && j == 0)
                memorize[i][j] = 3 * gridSize;
            else if(i == 0)
                memorize[i][j] = memorize[i][j - 1] + 1;
            else if(j == 0)
                memorize[i][j] = memorize[i - 1][j] + 1;
            else
                memorize[i][j] = MIN(memorize[i - 1][j], memorize[i][j - 1]) + 1;
    //从右下开始，从右往左，从下往上
    int newmemo;
    for(i = gridSize - 1;i >= 0;i --)
        for(j = gridColSize[i] - 1;j >= 0;j --)
            if(memorize[i][j]!= 0)
                if(i != gridSize - 1 && j != gridColSize[i] - 1){
                    newmemo = MIN(memorize[i + 1][j], memorize[i][j + 1]) + 1;
                    memorize[i][j] = MIN(memorize[i][j], newmemo);
                }
                else if(i != gridSize - 1)
                    memorize[i][j] = MIN(memorize[i][j], memorize[i + 1][j] + 1);
                else if(j != gridColSize[i] - 1)
                    memorize[i][j] = MIN(memorize[i][j], memorize[i][j + 1] + 1);
    int max = 0;
    for(i = 0;i < gridSize;i ++)
        for(j = 0;j < gridColSize[i];j ++)
            max = (memorize[i][j] > max ? memorize[i][j] : max);
    if(max != 0 && max < 3 * gridSize)
        return max;
    else
        return -1;

}
```
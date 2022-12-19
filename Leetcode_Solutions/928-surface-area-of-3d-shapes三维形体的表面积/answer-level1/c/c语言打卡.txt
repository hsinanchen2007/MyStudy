### 解题思路
遍历数组，加上总表面积，减去遮挡的表面积

### 代码

```c
int min(a, b){
    return (a > b ? b : a);
}

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i, j, area = 0;
    for(i = 0;i < gridSize;i ++)
        for(j = 0;j < gridColSize[i];j ++){
            area += (grid[i][j] > 0 ? 4 * grid[i][j] + 2 : 0);
            if(i != 0)
                area -= min(grid[i][j], grid[i - 1][j]) * 2;
            if(j != 0)
                area -= min(grid[i][j], grid[i][j - 1]) * 2;
        }
    return area;
}
```
### 解题思路
减去相加面

### 代码

```c
int min(int a, int b)
{
    return a < b ? a : b;
}
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int row = gridSize;
    int col = *gridColSize;
    int area = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int val = grid[i][j];
            if (val <= 0) {
                continue;
            }
            area += 4 * val + 2;           
            area -= (i == 0) ? 0 :  2 * min(grid[i-1][j], val);
            area -= (j == 0) ? 0 :  2 * min(grid[i][j-1], val);
        }
    }
    return area;
}
```
### 解题思路
首先每个网格上不看旁边结点时，表面积是a = 6 * v - 2 * (v - 1)前提是v要大于0，再依据旁边结点j（上下左右）判断其是否大于当前结点i，若j > i则a = a - i，若j <= i则a = a - j(理由：相邻的网格会遮盖正方体的表面),再将得到的a累加即可。

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int v = 0,a = 0;
    int area = 0;

    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < gridColSize[i]; j++)
        {
            v = grid[i][j];
            if(v > 0)
            {
                a = 6 * v - 2 * (v - 1);
            if(j - 1 >= 0)
            {
                if(grid[i][j-1] <= v) a = a - grid[i][j-1];
                else a = a - v;
            }
            if(i - 1 >= 0)
            {
                if(grid[i-1][j] <= v) a = a - grid[i-1][j];
                else a = a - v;
            }
            if(j + 1 < gridColSize[i])
            {
                if(grid[i][j+1] <= v) a = a - grid[i][j+1];
                else a = a - v;
            }
            if(i + 1 <gridSize)
            {
                if(grid[i+1][j] <= v) a = a - grid[i+1][j];
                else a = a - v;
            }
            area += a;
            }
            
        }
    }

    return area;
}
```
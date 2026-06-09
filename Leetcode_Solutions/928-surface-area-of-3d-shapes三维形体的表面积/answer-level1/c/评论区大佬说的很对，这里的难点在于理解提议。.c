### 解题思路
此处撰写解题思路

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int area = 0;
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<gridColSize[i]; j++) {
            if (grid[i][j] > 0) {
                area += (grid[i][j]*6 - (grid[i][j] -1)*2);

                //同一行左侧重叠
                if (j-1 >=0 && grid[i][j-1] > 0) {
                    int min = grid[i][j] > grid[i][j-1] ? grid[i][j-1] : grid[i][j];
                    area -= min*2;
                }

                //相邻行上侧重叠
                if (i-1>=0 && grid[i-1][j] > 0) {
                    int min = grid[i][j] > grid[i-1][j] ? grid[i-1][j] : grid[i][j];
                    area -= min*2;  
                }
            }
        }
    }
    return area;
}
```
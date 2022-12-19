### 解题思路


### 代码

```c
#define min(a, b) ((a) < (b) ? (a) : (b))

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    //总的立方体面积 - 相邻立方体不被展示的面积
    int sum = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            sum += grid[i][j] * 6;
            if(grid[i][j] > 1) sum -= (grid[i][j] - 1) * 2; //叠加的立方体块
            if(j > 0) sum -= min(grid[i][j], grid[i][j - 1]) * 2; //和左侧相邻的立方体块
            if(i > 0) sum -= min(grid[i][j], grid[i - 1][j]) * 2; //和上册相邻的立方体块
        }
    }
    return sum;
}
```
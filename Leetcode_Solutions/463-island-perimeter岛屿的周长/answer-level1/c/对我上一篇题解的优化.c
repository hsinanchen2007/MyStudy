### 解题思路
1. 思路和我上一篇题解一致
2. 放弃使用函数封装提高效率
### 代码

```c
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    for (int i=0; i<gridSize; i++){
        for (int j=0; j<*gridColSize; j++){
            if (grid[i][j] == 1){
                if (i-1 < 0 || grid[i-1][j] == 0) res++;
                if (i+1 > gridSize-1 || grid[i+1][j] == 0) res++;
                if (j-1 < 0 || grid[i][j-1] == 0) res++;
                if (j+1 > *gridColSize-1 || grid[i][j+1] == 0) res++;
            }
        }
    }
    return res;
}
```

### 解题思路
直接上代码

### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    bool unchanged = true;
    bool hasFresh = false;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == 1){
                if((i - 1 >= 0 && grid[i - 1][j] == 2)
                   || (i + 1 < gridSize && grid[i + 1][j] == 2)
                   || (j - 1 >= 0 && grid[i][j-1] == 2)
                   || (j + 1 < gridColSize[i] && grid[i][j + 1] == 2)){
                    grid[i][j] = -2;
                    unchanged = false;
                }else{
                    hasFresh = true;
                }
            }
        }
    }
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == -2) {
                grid[i][j] = 2;
            }
        }
    }
    if(unchanged){
        if(hasFresh) {
            return -1;
        } else {
            return 0;
        }
    }
    int steps = orangesRotting(grid, gridSize, gridColSize);
    return steps == -1 ? -1 : steps + 1;
}
```
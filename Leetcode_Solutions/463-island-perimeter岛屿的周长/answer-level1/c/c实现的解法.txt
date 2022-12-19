### 解题思路
顺序扫描每个方块“1”，得到其对边长的贡献值，最终累加得到周长

### 代码

```c
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridSize == 0 || gridColSize == NULL)
        return 0;
    int count = 0;
    for(int i = 0; i < gridSize; ++i){
        for(int j = 0; j < *gridColSize; ++j){
            if(grid[i][j] == 1){
                int edge = 4;
                int direct[4][2] = {1,0,-1,0,0,1,0,-1};
                for(int k = 0; k < 4; ++k){
                    int newi = i + direct[k][0];
                    int newj = j + direct[k][1];
                    if(newi < 0 || newi == gridSize || newj < 0 || newj == *gridColSize || grid[newi][newj] == 0)
                        continue;
                    --edge;
                }
                count += edge;


            }

        }
    }
    return count;
}
```
```
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int circle = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < (*gridColSize); j++) {
            if (grid[i][j] == 1) {
                circle +=4;
                if (i > 0 && grid[i-1][j] == 1) {
                    circle--;
                }
                if ((i + 1) < gridSize && grid[i + 1][j] == 1){
                    circle--;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    circle--;
                }
                if ((j + 1) < (*gridColSize) && grid[i][j + 1] == 1){
                    circle--;
                }
            }
        }        
    }
    return circle;
}
```

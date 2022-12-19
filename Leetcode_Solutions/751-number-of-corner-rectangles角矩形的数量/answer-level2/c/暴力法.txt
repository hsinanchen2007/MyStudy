### 解题思路
纯暴力法，这都能过

### 代码

```c
int countCornerRectangles(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    int rows = gridSize;
    int cols = gridColSize[0];
    for (int i = 0; i < rows - 1; i++) {
        int leftUpper = 0;
        for (int j = 0; j < cols - 1; j++) {
            if (grid[i][j] == 1) {
                leftUpper = j;
                int rightUpper = 0;
                for (int k = j+1; k < cols; k++) {
                    if (grid[i][k] == 1) {
                        rightUpper = k;
                        for (int n = i + 1; n < rows; n++) {
                            if (grid[n][leftUpper] == 1 && grid[n][rightUpper] == 1) {
                                res++;
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}
```
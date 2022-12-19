```c
int numIslands(char** grid, int gridSize, int* gridColSize){
    if (gridSize == 0) return 0;
    int num = 0;
    int queue[gridSize * (*gridColSize)][2];
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == '1') {
                num++;
                int head =0, tail = 0;
                queue[tail][0] = i;
                queue[tail][1] = j;
                grid[i][j] = '0';
                while (head <= tail) {
                    int row = queue[head][0];
                    int col = queue[head][1];
                    head++;
                    
                    int x[4] = {1, 0, -1, 0};
                    int y[4] = {0, 1, 0, -1};
                    
                    for (int k = 0; k < 4; ++k) {
                        int next_row = row + x[k];
                        int next_col = col + y[k];
                        if (next_row >= 0 && next_row < gridSize && next_col >= 0 && next_col < *gridColSize && grid[next_row][next_col] == '1') {
                            tail++;
                            queue[tail][0] = next_row;
                            queue[tail][1] = next_col;
                            grid[next_row][next_col] = '0';
                        }
                    }
                }
            }
        }
    }
    return num;
}
```

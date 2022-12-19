执行结果：通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :9.3 MB, 在所有 C 提交中击败了19.67%的用户

```
int numIslands(char** grid, int gridSize, int* gridColSize){
    int land = 1;
    char *gColur = NULL;
    int *queue = NULL;
    int head = 0;
    int tail = 0;
    int rid;
    int col;
    int tmp;
    if (gridSize == 0 || *gridColSize == 0) {
        return 0;
    }
    gColur = malloc(gridSize * (*gridColSize));
    queue = malloc(gridSize * (*gridColSize) * sizeof(int));
    memset(gColur, 0, gridSize * (*gridColSize));
    //memset(queue, 0, gridSize * (*gridColSize) * sizeof(int));
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            tmp = i * (*gridColSize) + j;
            if (gColur[tmp] == 1 || grid[i][j] == '0') {
                continue;
            }
            //printf("grid[%d][%d]=%d\n", i, j, grid[i][j]);
            head = 0;
            tail = 0;
            queue[head++] = tmp;
            gColur[tmp] = 1;
            while (tail != head && head < gridSize * (*gridColSize)) {
                rid = queue[tail] / (*gridColSize);
                col = queue[tail] % (*gridColSize);
                // 左
                if (col != 0) {
                    tmp = rid * (*gridColSize) + col - 1;
                    if (gColur[tmp] == 0 && grid[rid][col - 1] == '1') {
                        queue[head++] = tmp;
                        gColur[tmp] = 1;
                    }
                }
                // 右
                if (col != (*gridColSize) - 1) {
                    tmp = rid * (*gridColSize) + col + 1;
                    if (gColur[tmp] == 0 && grid[rid][col + 1] == '1') {
                        queue[head++] = tmp;
                        gColur[tmp] = 1;
                    }
                }
                // 上
                if (rid != 0) {
                    tmp = (rid - 1) * (*gridColSize) + col;
                    if (gColur[tmp] == 0 && grid[rid - 1][col] == '1') {
                        queue[head++] = tmp;
                        gColur[tmp] = 1;
                    }
                }
                if (rid != gridSize - 1) {
                    tmp = (rid + 1) * (*gridColSize) + col;
                    if (gColur[tmp] == 0 && grid[rid + 1][col] == '1') {
                        queue[head++] = tmp;
                        gColur[tmp] = 1;
                    }
                }
                tail++;
            }
            land++;
        }
    }
    
    return (land - 1);
}

```

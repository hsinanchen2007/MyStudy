```
typedef struct {
    int r;
    int c;
}fifostruct;

fifostruct fifolist[100000];

int Bfs(int **grid, int r, int c, int gridSize, int *gridColSize) {
    int ret = 1;
    int head = 0, tail = 0;
    int curr_c, curr_r;
    int vr[4] = {0, 1, 0, -1};
    int vc[4] = {1, 0, -1, 0};
    fifolist[tail].r = r;
    fifolist[tail].c = c;
    tail++;
    while(head != tail) {
        grid[fifolist[head].r][fifolist[head].c] = 1;
        //printf("out %d,  %d\n", fifolist[head].r, fifolist[head].c);
        r = fifolist[head].r;
        c = fifolist[head].c;
        head++;
        for(int i = 0; i < 4; i++) {
            curr_r = r + vr[i];
            curr_c = c + vc[i];
            
            if (curr_r < 0 || curr_r >= gridSize || curr_c < 0 || curr_c >= *gridColSize) {
                ret = 0;
                continue;
            }
            //printf("all %d,  %d, gird%d\n", curr_r, curr_c, grid[curr_r][curr_c]);
            if (grid[curr_r][curr_c] == 0) {
                //grid[curr_r][curr_c] = 1;
                fifolist[tail].r = curr_r;
                fifolist[tail].c = curr_c;
                //printf("in %d,  %d,\n", curr_r, curr_c);
                tail++;
            }
            
        }

    } 
    //printf("result ret %d\n", ret);
    return ret;
}


int closedIsland(int** grid, int gridSize, int* gridColSize){
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            
            if (grid[i][j] == 0) {
                printf("closedIsland %d,  %d, grid:%d\n",  i, j, grid[i][j]);
                ret += Bfs(grid, i, j, gridSize, gridColSize);
            }
        }
    }
   // printf("return num %d", ret);
    return ret;
}
```

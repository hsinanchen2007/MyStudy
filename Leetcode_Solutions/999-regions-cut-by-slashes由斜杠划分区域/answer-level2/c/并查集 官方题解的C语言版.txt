```
int find(int x, int* pre) {
    int r=x;
    while(pre[r]!=r) {
        r=pre[r];
    }
    int i=x, j;
    while (pre[i]!=r) {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}
void Union(int x, int y, int* pre) {
    int rx = find(x, pre);
    int ry = find(y, pre);
    if(rx!=ry) {
        pre[rx] = ry;
    }
    return;
}
int regionsBySlashes(char ** grid, int gridSize){
    int* pre = malloc(4*gridSize*gridSize*sizeof(int));
    for(int i=0;i<gridSize;i++) {
        for(int j=0;j<gridSize;j++) {
            int idx = 4*(i*gridSize+j);
            pre[idx] = idx;
            pre[idx+1] = idx+1;
            pre[idx+2] = idx+2;
            pre[idx+3] = idx+3;
            if(grid[i][j]==' ' || grid[i][j]=='/') {
                Union(idx,idx+3, pre);
                Union(idx+1,idx+2, pre);
            }
            if(grid[i][j]==' ' || grid[i][j]=='\\') {
                Union(idx,idx+1, pre);
                Union(idx+2,idx+3, pre);
            }
            if(j!=0) {
                Union(idx+3,idx-3, pre);
            }
            if(i!=0) {
                Union(idx,idx-4*gridSize+2, pre);
            }
        }
    }
    int sum = 0;
    for(int i=0;i<4*gridSize*gridSize;i++) {
        if(pre[i]==i) {
            sum++;
        }
    }
    free(pre);
    return sum;
}
```

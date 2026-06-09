```
#define max(a, b) a > b ? a : b

typedef struct {
    int x;
    int y;
    int layer;
}Queue;

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int row = gridSize, col = gridColSize[0];
    int res = 0;
    int front = 0, rear = 0;
    Queue* queue = (Queue*)calloc(row * col, sizeof(Queue));

    int x_shift[4] = {1, -1, 0, 0};
    int y_shift[4] = {0, 0, -1, 1};

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (grid[i][j] == 1) {         //一开始的陆地先入队列
                queue[rear].x = i;
                queue[rear].y = j;
                queue[rear++].layer = 0;    
            }
        }
    }
    if (rear == 0 || rear == row * col) {  //全是陆地 或者 全是海洋
        return -1;
    }

    while (front != rear) {
        int x = queue[front].x;
        int y = queue[front].y;
        int layer = queue[front++].layer;  
        //一开始的陆地全都为 layer=0  因此稍后遇到的海 到陆地的最近距离为0+1=1 以此类推
        
        res = max(res, layer);            //记录距离陆地最远的海

        for (int i = 0; i < 4; ++i) {      //由当前的陆地向四周扩展 填海造陆
            int nx = x + x_shift[i];        
            int ny = y + y_shift[i];            
            if (nx<0||nx>=row||ny<0||ny>=col||grid[nx][ny]==1) {//遇到陆地直接跳过
                continue;
            } else {                        //遇到了海
                queue[rear].x = nx;
                queue[rear].y = ny;
                queue[rear++].layer = layer + 1;  
                grid[nx][ny] = 1;         //海已经变成陆地 
            }

        }
    }
    return res;
}
```

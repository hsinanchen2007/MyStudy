### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a,b) ((a)>(b) ? (a) : (b))
typedef struct {
    int x;
    int y;
} Queue;
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || *gridColSize == 0) return 0;
    int x_shift[4] = {-1, 1, 0, 0};
    int y_shift[4] = {0, 0, -1, 1};
    Queue* Q = (Queue*) malloc(sizeof(Q) * gridSize * (*gridColSize));
    int front = 0; int rear = 0;
    int res = 0;
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<*gridColSize; j++) {
            int tmp = 0;
            if (grid[i][j] == 1) {
                Q[rear].x = i;
                Q[rear].y = j;
                rear++;
                grid[i][j] = 0;
                tmp++;
                while (front != rear) {
                    int x = Q[front].x;
                    int y = Q[front].y;
                    front++;
                    for (int k=0; k<4; k++) {
                        int xx = x + x_shift[k];
                        int yy = y + y_shift[k];
                        if (xx<0 || xx>gridSize-1 || yy<0 || yy>*gridColSize-1)
                            continue;
                        if (grid[xx][yy] == 1) {
                            Q[rear].x = xx;
                            Q[rear].y = yy;
                            rear++;
                            grid[xx][yy] = 0;
                            tmp++;
                        }
                    }
                }
            }
            res = res > tmp ? res : tmp;
        }
    }
    return res;
}
```
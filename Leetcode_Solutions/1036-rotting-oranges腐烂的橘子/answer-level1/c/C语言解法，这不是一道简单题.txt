```
typedef struct {
    int x;
    int y;
    int lev;
}Queue;

/* 标准BFS框架, 队列实现广度优先遍历 */
/* 坏橘子入队列, 出队列时, 将周边的好橘子染坏, 坏橘子再入队, 依次循环 */
/* 当队列为空时, 说明没有好橘子了, 此时判断如果还有好橘子, 返回-1, 否则返回level */
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = *gridColSize;
    //队列的性质是先进先出，后进后出，尾部插入新数据，头部出数据
    Queue *Q = (Queue *)malloc(sizeof(Queue)*m*n);
    memset(Q, 0, sizeof(Queue)*m*n);
    int front = 0;
    int rear = 0;
    int dir[4][4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int lev = 0;
    int x = 0, y = 0, newX = 0, newY = 0;
    //1 将怀橘子入队
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2){
                Q[rear].x = i;
                Q[rear].y = j;
                Q[rear].lev = 0;
                rear++;
            }
        }  
    }   
    //2 BFS 遍历4个方向
    while(front != rear){
        x = Q[front].x;
        y = Q[front].y;
        lev = Q[front].lev;
        front++;
        for(int i = 0; i < 4; i++) {
            newX = x + dir[i][0]; //在原位置基础之上 进行上下左右搜索
            newY = y + dir[i][1];
            if(newX < 0 || newX >= m || newY < 0 || newY >= n || (grid[newX][newY] != 1)) {
                continue;
            }
            grid[newX][newY] = 2; //好橘子被染坏
            Q[rear].x = newX;
            Q[rear].y = newY;
            Q[rear].lev = lev + 1;
            rear++;
        }
    }
    //3 遍历完后查看是否还有好橘子没
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                free(Q);
                return -1;
            }
        }
    }        
            
    return lev;
}
```

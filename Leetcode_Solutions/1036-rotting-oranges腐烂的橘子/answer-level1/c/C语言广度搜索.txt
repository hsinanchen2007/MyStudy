### 解题思路
模板题

### 代码

```c
/*使用广度优先搜索，遍历完后在再进行检查*/
#define EnQueue(x, q)  (q[rear++] = x)
#define DeQueue(q)     (q[front++])
#define IsQueueEmpty   (front == rear)
#define QueueLength(q)    (rear - front)
typedef struct Position_{
    int row;
    int col;
}Position;
bool IsInBornd(Position size, Position x)
{
    return x.row >= 0 && x.row < size.row && x.col >= 0 && x.col < size.col;
}
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    Position queue[gridSize * gridColSize[0]];
    int front = 0;
    int rear = 0;
    Position size = {.row = gridSize, .col = gridColSize[0]};
    int orangeNum = 0;
    int rotOrangeNum = 0;

    //先把所有当前腐烂的节点加入到队列
    
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] != 0){
                orangeNum++;
            }
            if (grid[i][j] == 2){
                Position pos = {.row = i, .col = j};
                rotOrangeNum++;
                EnQueue(pos, queue);
            }
        }
    }
    if (orangeNum == 0){
        return 0;
    }
    //printf("%d:%d\n", orangeNum, rotOrangeNum);
    int step = 0;
    while (!IsQueueEmpty){
        int qLen = QueueLength(queue);
        for (int i = 0; i < qLen; i++){
            Position cur = DeQueue(queue);
            Position dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int j = 0; j < 4; j++){
                Position next;
                next.row = cur.row + dir[j].row;
                next.col = cur.col + dir[j].col;
                if (!IsInBornd(size, next)){
                    continue;
                }
                if (grid[next.row][next.col] == 1){
                    grid[next.row][next.col] = 2;
                    rotOrangeNum++;
                    EnQueue(next, queue);
                }
            }
        }
        step++;
        //printf("setp %d:%d\n", step, rotOrangeNum);
    }
    //printf("anfter setp %d: %d:%d\n", step, orangeNum, rotOrangeNum);
    if (rotOrangeNum == orangeNum) {
        return step - 1;
    } else {
        return -1;
    }
}
```
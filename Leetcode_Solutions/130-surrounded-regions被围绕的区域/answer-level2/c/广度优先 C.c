思路：
1.先遍历四条边，找到所有O,然后存入队列之中。
2.进行广度优先搜索，将所有与边界的O有相连关系的O都打上“不更改的标签”
3.对整个图刷新，将所有无“不更改标签”的O都刷成X
```
#define QUEUESIZE 1000
int dire[4][2] = {{1, 0},{-1, 0}, {0, 1}, {0, -1}};
void InitQueue(char** board, int row, int col, int *rear, int front, int q[][2]) {
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            if ((i == 0 || i == row - 1 || j == 0 || j == col - 1) && board[i][j] == 'O') {
                if ((*rear + 1) % QUEUESIZE == front) {
                    printf("queue is full");
                    return;
                }
                q[*rear][0] = i;
                q[*rear][1] = j;
                *rear = (*rear + 1) % QUEUESIZE;
            } 
        }
    }
}
void solve(char** board, int boardSize, int* boardColSize){
    if (boardSize == 0 || (boardColSize != NULL && boardColSize[0] == 0)) {
        return;
    }
    int rear = 0;
    int front = 0;
    int q[QUEUESIZE][2] = {0};

    int flag[boardSize][boardColSize[0]];
    memset(flag, 0, sizeof(int) * boardSize * boardColSize[0]);

    InitQueue(board, boardSize, boardColSize[0], &rear, front, q);

    while (rear != front) {
        int x = q[front][0];
        int y = q[front][1];
        flag[x][y] = 1;
        front = (front + 1) % QUEUESIZE;
        for (int i = 0;i < 4;i++) {
            int tmpx = x + dire[i][0];
            int tmpy = y + dire[i][1];

            if(tmpx > 0 && tmpx < boardSize && tmpy > 0 && tmpy < boardColSize[0] && board[tmpx][tmpy] == 'O' && flag[tmpx][tmpy] == 0) {
                flag[tmpx][tmpy] = 1;
                q[rear][0] = tmpx;
                q[rear][1] = tmpy;
                rear = (rear + 1) % QUEUESIZE;
            }
        }

    }

    for (int i = 0;i < boardSize; i++) {
        for(int j = 0;j < boardColSize[0];j++) {
            if (board[i][j] == 'O' && flag[i][j] == 0) {
                    board[i][j] = 'X';
            }
        }
    }
    return ;
}
```

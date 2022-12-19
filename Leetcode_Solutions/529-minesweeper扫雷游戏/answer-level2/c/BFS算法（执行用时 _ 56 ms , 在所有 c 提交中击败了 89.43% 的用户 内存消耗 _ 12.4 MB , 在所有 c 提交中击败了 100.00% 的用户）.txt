```
#define QUEUE_SIZE 1000

typedef struct {
    int x;
    int y;
}Point;
Point dire[8] = {{1, 1},{1, 0},{1, -1},{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

void AddPoint(Point *dst, Point *src1, Point *src2) {
    dst->x = src1->x + src2->x;
    dst->y = src1->y + src2->y;
}
void SetPoint(Point *src, Point *dst) {
    dst->x = src->x;
    dst->y = src->y;
}
void Succ(int *i) {
    *i = (*i + 1) % QUEUE_SIZE;
}
bool IsPointValid(Point target, int row, int col) {
    if (target.x >= 0 && target.x < row && target.y >= 0 && target.y < col) {
        return true;
    } else {
        return false;
    }
}
int CalBoomNum(char** board, int row,int col, Point target) {
    int boomSum = 0;
    for (int i = 0;i < 8;i++) {
        Point around;
        AddPoint(&around, &target, &dire[i]);
        if (IsPointValid(around, row, col) && board[around.x][around.y] == 'M') {
            boomSum++;
        }
    }
    return boomSum;
}
void PintMap(char** board, int row, int col) {
    printf("****************\n");
    for (int i = 0;i < row; i++) {
        for (int j = 0;j < col;j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void PintQueue(Point *arr, int rear, int front) {
    printf("\n");
    while (rear != front) {
        printf("%d %d|", arr[front].x,arr[front].y);
        Succ(&front);
    }
    printf("\n");
}
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    
    *returnSize = boardSize;
    if (boardSize == 0) {
        *returnColumnSizes = NULL;
        return board;
    }
    *returnColumnSizes = malloc(sizeof(int) * boardSize);
    for (int i = 0;i < boardSize;i++) {
        (*returnColumnSizes)[i] = boardColSize[0];
    }
    int rear = 0;
    int front = 0;
    Point queue[QUEUE_SIZE];
    memset(queue, 0, sizeof(Point) * QUEUE_SIZE);

    queue[rear].x = click[0];
    queue[rear].y = click[1];
    Succ(&rear);

    while (rear != front) {
        //PintMap(board, boardSize, boardColSize[0]);
        //PintQueue(queue, rear, front);
        Point tmp;
        SetPoint(&queue[front], &tmp);
        Succ(&front);
        if (board[tmp.x][tmp.y] == 'M') {
            board[tmp.x][tmp.y] = 'X';
        } else if (board[tmp.x][tmp.y] == 'E') {
            int aroundBoom = CalBoomNum(board, boardSize, boardColSize[0], tmp);
            if (aroundBoom > 0) {
                board[tmp.x][tmp.y] = '0' + aroundBoom;
            } else if (aroundBoom == 0) {
                board[tmp.x][tmp.y] = 'B';
                for (int i = 0;i < 8;i++) {
                    Point around;
                    AddPoint(&around, &tmp, &dire[i]);
                    if (IsPointValid(around, boardSize, boardColSize[0]) && board[around.x][around.y] == 'E') {
                        SetPoint(&around, &queue[rear]);
                        Succ(&rear);
                    }
                }
            }
            
        }
        
    }
    
    return board;
}
```

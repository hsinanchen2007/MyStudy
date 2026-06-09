#define MAX_QUEUE_SIZE 10000

typedef struct {
    int i;
    int j;
}Pos;

typedef struct {
    Pos pos[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue queue;

void QueAdd (Pos pos) {    
    queue.pos[queue.front] = pos;
    queue.front = (queue.front + 1) % (MAX_QUEUE_SIZE);
}

Pos QueDel ()
{
    Pos pos = queue.pos[queue.rear];
    queue.rear = (queue.rear + 1) % (MAX_QUEUE_SIZE);
    return pos;
} 

bool QueIsEmpty()
{
    return (queue.rear == queue.front);
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (board == NULL || boardSize == 0) return;
    int m = boardSize;
    int n = *boardColSize;
    memset(&queue, 0, sizeof(Queue));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 从边缘第一个是o的开始搜索
            bool isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1;
            if (isEdge && board[i][j] == 'O') {
                bfs(board, boardSize, boardColSize, i, j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }
        }
    }
}

void bfs(char** board, int boardSize, int* boardColSize, int i, int j) {    
    Pos pos = {i , j}; 
    QueAdd(pos);
    board[i][j] = '#';
    while (!QueIsEmpty()) {
        Pos current = QueDel();
        // 上
        if (current.i - 1 >= 0 
            && board[current.i - 1][current.j] == 'O') {
            Pos tmpPos = {current.i - 1, current.j};
            QueAdd(tmpPos);
            board[current.i - 1][current.j] = '#';
            // 没有continue.
        }
        // 下
        if (current.i + 1 <= (boardSize - 1)
            && board[current.i + 1][current.j] == 'O') {
            Pos tmpPos = {current.i + 1, current.j};
            QueAdd(tmpPos);
            board[current.i + 1][current.j] = '#';      
        }
        // 左
        if (current.j - 1 >= 0 
            && board[current.i][current.j - 1] == 'O') {
            Pos tmpPos = {current.i, current.j - 1};
            QueAdd(tmpPos);
            board[current.i][current.j - 1] = '#';
        }
        // 右
        if (current.j + 1 <= ((*boardColSize) - 1)
            && board[current.i][current.j + 1] == 'O') {
            Pos tmpPos = {current.i, current.j + 1};
            QueAdd(tmpPos);
            board[current.i][current.j + 1] = '#';
        }
    }
}
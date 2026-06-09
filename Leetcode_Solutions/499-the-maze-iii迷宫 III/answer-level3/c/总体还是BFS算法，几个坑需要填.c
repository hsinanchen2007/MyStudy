总体还是BFS算法，几个坑需要填：
1. 如果想题目一样一个方向走到底算一步，则可能不符合字典序要求，因为BFS步数是一格一步，而不是一个方向走到底一步；所以还是要一格一格走；
2. 一格一格走，可能会从不同的方向路过交叉点，这种点算合法，参考IsCross函数。

#define MAX_SIZE 30 * 30
#define NULL_PTR 0

struct NodeInfoSt {
    int row;
    int col;
    char dir;
    int parent;
    int self;
    bool isCross;
};

struct QueueSt {
    int idxHead;
    int idxTail;
    int qty;
    struct NodeInfoSt nodes[MAX_SIZE];
    int** maze;
    int mazeSize;
    int* mazeColSize;
    int* hole;
};

void CreateQueue(struct QueueSt* queue, int** maze, int mazeSize, int* mazeColSize)
{
    queue->idxHead = 0;
    queue->idxTail = 0;
    queue->qty = 0;
    memset(queue->nodes, 0, MAX_SIZE * sizeof(struct NodeInfoSt));
    queue->maze = maze;
    queue->mazeSize = mazeSize;
    queue->mazeColSize = mazeColSize;
    //queue->hole = hole;
    return;
}

struct NodeInfoSt* GetNodeOut(struct QueueSt* queue)
{
    if (queue->qty == 0) {
        return NULL_PTR;
    }

    int idx = queue->idxHead;
    queue->idxHead++;
    queue->qty--;
    return queue->nodes + idx;
}

bool IsCross(struct QueueSt* queue, int row, int col)
{
    if (row == 0) {
        return false;
    }
    if (row == queue->mazeSize - 1) {
        return false;
    }
    if (col == 0) {
        return false;
    }
    if (col == (queue->mazeColSize[row] - 1)) {
        return false;
    }

    if (queue->maze[row][col - 1] == 1) {
        return false;
    }
    if (queue->maze[row][col + 1] == 1) {
        return false;
    }
    if (queue->maze[row - 1][col] == 1) {
        return false;
    }
    if (queue->maze[row + 1][col] == 1) {
        return false;
    }
    return true;
}

void AppendNode(struct QueueSt* queue, struct NodeInfoSt* node)
{
    node->self = queue->idxTail;
    node->isCross = IsCross(queue, node->row, node->col);
    queue->nodes[queue->idxTail] = *node;
    queue->idxTail++;
    queue->qty++;

    return;
}

int GetQty(struct QueueSt* queue)
{
    return queue->qty;
}

bool IsEmpty(struct QueueSt* queue)
{
    return queue->qty == 0;
}

bool IsVisited(struct QueueSt* queue, int row, int col, int dir)
{
    for (int i = 0; i < queue->idxTail; i++) {
        if (queue->nodes[i].col == col
             && queue->nodes[i].row == row
             && !(queue->nodes[i].isCross)) {
            return true;
        }
    }
    return false;
}

bool CanStep(struct QueueSt* queue, int nodeIdx, char dir)
{
    struct NodeInfoSt node;
    node.row = queue->nodes[nodeIdx].row;
    node.col = queue->nodes[nodeIdx].col;

    switch (dir) {
    case 'd':
        if (node.row == (queue->mazeSize - 1)) {
            return false;
        }
        if (queue->maze[node.row + 1][node.col] == 1) {
            return false;
        }
        return true;

    case 'l':
        if (node.col == 0) {
            return false;
        }
        if (queue->maze[node.row][node.col - 1] == 1) {
            return false;
        }
        return true;

    case 'r':
        if (node.col == (queue->mazeColSize[node.row] - 1)) {
            return false;
        }
        if (queue->maze[node.row][node.col + 1] == 1) {
            return false;
        }
        return true;

    case 'u':
        if (node.row == 0) {
            return false;
        }
        if (queue->maze[node.row - 1][node.col] == 1) {
            return false;
        }
        return true;

    default:
        return false;
    }
}

void TakeStep(struct QueueSt* queue, int parent, char dir)
{
    if (queue->nodes[parent].dir != 0
        && CanStep(queue, parent, queue->nodes[parent].dir)
        && queue->nodes[parent].dir != dir) {
        return;
    }

    if (!CanStep(queue, parent, dir)) {
        return;
    }

    struct NodeInfoSt node;
    node.row = queue->nodes[parent].row;
    node.col = queue->nodes[parent].col;
    node.parent = parent;
    node.dir = dir;

    switch (dir) {
    case 'd':
        node.row++;
        break;

    case 'l':
        node.col--;
        break;

    case 'r':
        node.col++;
        break;

    case 'u':
        node.row--;
    default:
        break;
    }

    if (IsVisited(queue, node.row, node.col, dir)) {
        return;
    }

    AppendNode(queue, &node);
    return;
}

char g_rtnStr[MAX_SIZE];

char* GetRtnStr(struct QueueSt* queue, struct NodeInfoSt* node)
{
    char tmpStr[MAX_SIZE];
    memset(tmpStr, 0, MAX_SIZE);
    int idxRtnStr = 0;
    while(node->self != 0) {
        tmpStr[idxRtnStr++] = node->dir;
        node = queue->nodes + node->parent;
    }

    memset(g_rtnStr, 0, MAX_SIZE);
    int idx = 0;
    g_rtnStr[idx++] = tmpStr[idxRtnStr - 1];
    for (int i = 1; i < idxRtnStr; i++) {
        if (tmpStr[idxRtnStr - i - 1] == g_rtnStr[idx - 1]) {
            continue;
        }
        g_rtnStr[idx++] = tmpStr[idxRtnStr - i - 1];
    }
    return g_rtnStr;
}

char* findShortestWay(int** maze, int mazeSize, int* mazeColSize, int* ball, int ballSize, int* hole, int holeSize)
{
    struct QueueSt queue;
    CreateQueue(&queue, maze, mazeSize, mazeColSize);

    struct NodeInfoSt node;
    node.row = ball[0];
    node.col = ball[1];
    node.dir = 0;
    node.parent = 0;
    node.self = 0;
    AppendNode(&queue, &node);

    while (!IsEmpty(&queue)) {
        struct NodeInfoSt* pNode = GetNodeOut(&queue);
        if (pNode->row == hole[0] && pNode->col == hole[1]) {
            return GetRtnStr(&queue, pNode);
        }
        TakeStep(&queue, pNode->self, 'd');
        TakeStep(&queue, pNode->self, 'l');
        TakeStep(&queue, pNode->self, 'r');
        TakeStep(&queue, pNode->self, 'u');
    }

    return "impossible";
}

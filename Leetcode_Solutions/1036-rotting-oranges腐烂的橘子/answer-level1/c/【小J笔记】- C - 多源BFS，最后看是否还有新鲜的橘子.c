- 代码没什么好说的，基本的BFS写法
```
#define MAX_QUEUE_SIZE (110)
#define TRUE (1)
#define FALSE (0)
#define NULL_PTR (0)

int g_row;
int g_col;
int g_dir[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

typedef struct {
    int step;
    int row;
    int col;
}QueueNode;

QueueNode g_queue[MAX_QUEUE_SIZE];
int g_tail;
int g_head;

int IsEmpty() 
{
    return (g_tail == g_head);
}

void Push(QueueNode *node)
{
    if (g_tail < MAX_QUEUE_SIZE) {
        g_queue[g_tail].step = node->step;
        g_queue[g_tail].row = node->row;
        g_queue[g_tail].col = node->col;
        g_tail++;
    }
}

void Front(QueueNode *node)
{
    if (IsEmpty()) {
        return;
    }
    node->step = g_queue[g_head].step;
    node->row = g_queue[g_head].row;
    node->col = g_queue[g_head].col;
    g_head++;
}

void CreateNode(QueueNode *node, int step, int row, int col)
{
    node->step = step;
    node->row = row;
    node->col = col;
}

int IsValidCrood(int row, int col)
{
    if ((row < 0) || (row > g_row)) {
        return FALSE;
    }
    if ((col < 0) || (col > g_col)) {
        return FALSE;
    }
    return TRUE;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int i;
    int j;
    int row;
    int col;
    int sonRow;
    int sonCol;
    int step = 0;
    QueueNode node;
    QueueNode sonNode;
    if ((grid == NULL_PTR) || (gridColSize == NULL_PTR)) {
        return -1;
    }    
    g_head = g_tail = 0;
    g_row = gridSize - 1;
    g_col = gridColSize[0] - 1;
    for (i = 0; i <= g_row; i++) {
        for (j = 0; j <= g_col; j++) {
            if (grid[i][j] == 2) {
                CreateNode(&node, 0, i, j);
                Push(&node);                
            }
        }
    }
    while (IsEmpty() == FALSE) {
        Front(&node);        
        row = node.row;
        col = node.col;
        step = node.step;
        for (i = 0; i < 4; i++) {
            sonRow = row + g_dir[i][0];
            sonCol = col + g_dir[i][1];
            if ((IsValidCrood(sonRow, sonCol) == TRUE) && 
                (grid[sonRow][sonCol] == 1)) {
                    CreateNode(&sonNode, node.step + 1, sonRow, sonCol);
                    Push(&sonNode);                    
                    grid[sonRow][sonCol] = 2;
            }
        }
    }
    for (i = 0; i <= g_row; i++) {
        for (j = 0; j <= g_col; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return step;
}
```

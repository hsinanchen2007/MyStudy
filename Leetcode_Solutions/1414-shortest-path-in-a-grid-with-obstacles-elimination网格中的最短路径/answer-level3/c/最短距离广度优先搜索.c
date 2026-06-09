### 解题思路
注意两点：
1.第一次到达时肯定时最短距离需要直接返回。
2.如果一个点第二次到达时如果消耗的k值更少，则需要再次考察，否则上次消耗k比较多的有可能无法到达。
### 代码

```c
/*广度优先搜索*/
typedef struct Cell_{
    int row;
    int col;
}Cell;
typedef struct BSTTable_{
    bool v;
    int k;
    int setp;
    Cell parent;
}BSTTable;
void InitTable(Cell size, BSTTable table[size.row][size.col]){
    BSTTable tmp = {.v = false, .k = 0, .setp = INT_MAX, {.row = -1, .col = -1}};
    for (int i = 0; i < size.row; i++){
        for (int j = 0; j < size.col; j++){
            table[i][j] = tmp;
        }
    }
}
#define EnQueue(x, q) (q[rear++] = x )
#define DeQueue(q)    (q[front++])
#define IsQueueEmpty   (rear == front)
bool IsOutBound (Cell cur, Cell size)
{
    return cur.row < 0 || cur.row >= size.row || cur.col < 0 || cur.col >= size.col;
}
int shortestPath(int** grid, int gridSize, int* gridColSize, int k){
    Cell size = {.row = gridSize, .col = gridColSize[0]};
    BSTTable table[size.row][size.col];
    InitTable(size, table);
    Cell queue[size.row * size.col + 10000];
    int front = 0;
    int rear = 0;
    Cell start = {.row = 0, .col = 0};
    EnQueue(start, queue);
    table[start.row][start.col].v = true;
    table[start.row][start.col].k = 0;
    table[start.row][start.col].setp = 0;
    table[start.row][start.col].parent.row = -1;
    table[start.row][start.col].parent.col = -1;
    while (!IsQueueEmpty){
        Cell cur = DeQueue(queue);
        if (cur.row == size.row - 1 && cur.col == size.col - 1){
            return table[size.row - 1][size.col - 1].setp;
        }
        //printf("dequeue: %d:%d\n", cur.row, cur.col);
        Cell dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++){
            Cell next;
            next.row = cur.row + dir[i].row;
            next.col = cur.col + dir[i].col;
            if (IsOutBound(next, size)){
                continue;
            }
            int K = table[cur.row][cur.col].k + grid[next.row][next.col];
            int setp = table[cur.row][cur.col].setp + 1;
            //printf("next:%d:%d -->%d,%d\n", next.row, next.col, K, setp );
            if (K <= k && (table[next.row][next.col].v == false || (table[next.row][next.col].v == true && K < table[next.row][next.col].k))){
                //printf("enter:%d:%d -->%d,%d\n", next.row, next.col, K, setp );
                EnQueue(next, queue);
                table[next.row][next.col].v = true;
                table[next.row][next.col].k = K;
                table[next.row][next.col].setp = setp;
            }
        }
    }
    return table[size.row - 1][size.col - 1].v == true ? table[size.row - 1][size.col - 1].setp : -1;
}
```
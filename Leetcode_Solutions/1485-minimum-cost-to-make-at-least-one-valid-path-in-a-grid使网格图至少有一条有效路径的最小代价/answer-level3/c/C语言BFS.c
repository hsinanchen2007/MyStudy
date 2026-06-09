### 解题思路
1.求最短路径使用BFS模板
2.需要注意的几个点， 
2.1下一个可以到达的点，如果没有访问，则直接加入考察点。
2.2如果有访问过，但是新的路径的Cost更小则使用新的Cost重新考察。
3.到达终点时不能退出，还要继续考察是否还有更短路径。

这个题目应该也可以使用DFS，最终都要考察所有可能的路径选择最优。
### 代码

```c

typedef struct Point_{
    int row;
    int col;
}Point;
struct BFSTable{
    bool v;
    int dist;
    int cost;
    Point path;
};
#define MAX_QUEUE_LEN   1000000
#define MAX_DIR 4
#define EnQueue(x, q) (q[tail++] = x)
#define DeQueue(q)    (q[head++])
#define IsQueueEmpty  (head == tail)

bool IsInBound(Point x, Point size)
{
    return x.row >= 0 && x.row < size.row && x.col >= 0 && x.col < size.col;
}
void InitBFSTable(Point size, struct BFSTable table[size.row][size.col])
{
    struct BFSTable tmp = {.v = false, .dist = INT_MAX, .cost = INT_MAX, .path.row = 0, .path.col = 0};
    for (int i = 0; i < size.row; ++i) {
        for (int j = 0; j < size.col; ++j) {
            table[i][j] = tmp;
        }
    }
}
void PrintBFSTable(Point size, struct BFSTable table[size.row][size.col])
{
    //struct BFSTable tmp = {.v = false, .dist = INT_MAX, .cost = 0, .path.row = 0, .path.col = 0};
    for (int i = 0; i < size.row; ++i) {
        for (int j = 0; j < size.col; ++j) {
            printf("%d:%d ", table[i][j].v, table[i][j].cost);
        }
        printf("\n");
    }
    printf("\n");
}
void PrintPath(Point size, struct BFSTable table[size.row][size.col], Point pos)
{
    Point parent = table[pos.row][pos.col].path;
    if (!(pos.row == parent.row && pos.col == parent.col)){
        PrintPath(size, table, parent);
        printf(" ---> ");
    }
    printf("[%d:%d]", pos.row, pos.col);
}
/*
使用BFS 如果重复到达某个点
如果Cost相等，不用更新
如果Cost大于，之前到达的Cost则更新重新考察。
如果Cost小于，则丢弃该条路径
*/
bool DirMath(int nDir, int dir){
    return nDir + 1 == dir;
}
int minCost(int** grid, int gridSize, int* gridColSize){
    Point size = {.row = gridSize, .col = gridColSize[0]};
    struct BFSTable table[size.row][size.col];
    InitBFSTable(size, table);
    Point start = {.row = 0, .col = 0};
    Point queue[MAX_QUEUE_LEN];
    int head = 0;
    int tail = 0;
    EnQueue(start, queue);
    table[start.row][start.col].v = true;
    table[start.row][start.col].cost = 0;
    while (!IsQueueEmpty){
        Point cur = DeQueue(queue);
        //这里不能退出需要继续考察有没有更短路径。
        //if (cur.row == size.row - 1 && cur.col == size.col - 1){
        //    break;
        //}
        Point dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++){
            Point next;
            next.row = cur.row + dir[i].row;
            next.col = cur.col + dir[i].col;
            if (!IsInBound(next, size)){
                continue;
            }
            
            int cost = table[cur.row][cur.col].cost;
            if (!DirMath(i, grid[cur.row][cur.col])){
                //printf("!!!:i:%d-->%d:%d\n", i, cur.row, cur.col);
                cost++;
            }
            //这个点没有考察过
            //这个点考察过但是第二次到达时的Cost小于原来的Cost
            if (table[next.row][next.col].v == false || 
            (table[next.row][next.col].v == true && cost < table[next.row][next.col].cost)){
                table[next.row][next.col].cost = cost;
                table[next.row][next.col].v = true;
                //printf("enQueue:i:%d-->%d:%d\n", i, next.row, next.col);
                EnQueue(next, queue);
            }
        }
    }
    //PrintBFSTable(size, table);
    return table[size.row - 1][size.col - 1].cost;
}

```
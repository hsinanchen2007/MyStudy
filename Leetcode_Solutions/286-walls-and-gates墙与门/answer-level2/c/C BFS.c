![image.png](https://pic.leetcode-cn.com/0e38ab9639699d50475ffa4fde7cd8998b4e528e76421e5c03df37cdb311373a-image.png)


#define  INF_VAL  2147483647
#define  GATE_VAL  0
#define  DIR_SIZE  4
NODE g_dir[DIR_SIZE] = {
    { 1,  0},
    {-1,  0},
    { 0,  1},
    { 0, -1}
};
static void Bfs(int** rooms, int roomsSize, int* roomsColSize)
{
    int i, j, cnt, colSize;
    MyCircularQueue* que = NULL;
    NODE node = {0};
    NODE* pn = NULL;
    int step = 0;
    int trow, tcol;
    colSize = *roomsColSize;
    // init
    que = CircularQueueCreate(roomsSize * (*roomsColSize));
    if (que == NULL) {
        return;
    }
    // start form gate node
    for (i = 0; i < roomsSize; i++) {
        for (j = 0; j < colSize; j++) {
            if (rooms[i][j] == GATE_VAL) {
                node.row = i;
                node.col = j;
                CircularQueueEnQueue(que, node);
            }
        }
    }
    // Bfs start
    while (CircularQueueIsEmpty(que) == FALSE) {
        step += 1;
        cnt = CircularQueueItemCount(que);
        for (i = 0; i < cnt; i++) {
            pn = CircularQueueFront(que);
            for (j = 0; j < DIR_SIZE; j++) {
                trow = pn->row + g_dir[j].row;
                tcol = pn->col + g_dir[j].col;
                if (trow < 0 || trow >= roomsSize || tcol < 0 || tcol >= colSize || 
                    rooms[trow][tcol] != INF_VAL) {
                        continue;
                }
                rooms[trow][tcol] = rooms[pn->row][pn->col] + 1;
                node.row = trow;
                node.col = tcol;
                CircularQueueEnQueue(que, node);
            }
            CircularQueueDeQueue(que);
        }
    }
    CircularQueueFree(que);
    return;
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize)
{
    if (rooms == NULL || roomsSize == 0 || roomsColSize == NULL || *roomsColSize == 0) {
        return;
    }

    Bfs(rooms, roomsSize, roomsColSize);
}
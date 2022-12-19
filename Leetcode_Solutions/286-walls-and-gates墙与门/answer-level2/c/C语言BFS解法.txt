#define INF 2147483647 
int g_stack[100000][2];
int g_index1;
int g_index2;
int g_size;
int g_col;
/*判断周围的点入栈，以及赋路径值*/
void judge(int **rooms, int x, int y, int deep)
{
    if (x >= g_size || x < 0 || y >= g_col || y < 0) {
        return;
    }
    if (rooms[x][y] == INF) {
        rooms[x][y] = deep;
        g_stack[g_index2][0] = x;
        g_stack[g_index2][1] = y;
        g_index2++;
    }
    return;
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){
    if (rooms == NULL || roomsSize == 0 || roomsColSize == NULL) {
        return;
    }
    int i, j;
    g_index1 = 0;
    g_index2 = 0;
    g_size = roomsSize;
    g_col = roomsColSize[0];
    int deep = 0;
    int tmp = 0;
    /*初始门先入栈*/
    for (i = 0; i < roomsSize; i++) {
        for (j = 0; j < roomsColSize[0]; j++) {
            if (rooms[i][j] == 0) {
                g_stack[g_index2][0] = i;
                g_stack[g_index2][1] = j;
                g_index2++;
            }
        }
    }
    /*从门开始，寻找周围的空房间*/
    while (g_index1 < g_index2) {
        deep++;
        tmp = g_index2;
        for (; g_index1 < tmp; g_index1++) {
            judge(rooms, g_stack[g_index1][0] - 1, g_stack[g_index1][1], deep);
            judge(rooms, g_stack[g_index1][0] + 1, g_stack[g_index1][1], deep);
            judge(rooms, g_stack[g_index1][0], g_stack[g_index1][1] - 1, deep);
            judge(rooms, g_stack[g_index1][0], g_stack[g_index1][1] + 1, deep);
        }
    }
}
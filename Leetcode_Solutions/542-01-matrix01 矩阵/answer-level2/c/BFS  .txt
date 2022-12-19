### 解题思路
标准BFS 先将所有零点位置坐标入队并表示对于深度同步标记已访问，遍历所有所有队列里面未被访问1的节点并将节点更改为源节点深度+1. 

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct{
    unsigned short x;
    unsigned short y;
    unsigned short level;
}MatrixQueue; 
#define MAX_QUEUE_LEN 10000
int g_direcct[4][2] = {
    {-1, 0},//上
    {1, 0},//下
    {0, -1},//左
    {0, 1}//右
};

int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    if (matrixSize == 0 || *matrixColSize == 0 || matrix == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int head, tail, i, j;
    int row = matrixSize;
    int col = *matrixColSize;
    MatrixQueue* queue = malloc(sizeof(MatrixQueue) * MAX_QUEUE_LEN);
    *returnColumnSizes = malloc(sizeof(int) * matrixSize);
    MatrixQueue* cur = NULL;
    MatrixQueue next;
    int** visit = NULL;
    memset(queue, 0, sizeof(MatrixQueue) * MAX_QUEUE_LEN);
    head = tail = 0;
    visit = malloc(sizeof(int *) * matrixSize);
    for (i = 0; i < row; i++) {
        visit[i] = malloc(sizeof(int) * col);
        memset(visit[i] , 0, sizeof(int) * col);
    }    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                queue[tail].x = i;
                queue[tail].y = j;
                queue[tail].level = 0;
                visit[i][j] = 1;
                tail++;
            }
        }
        (*returnColumnSizes)[i] = col;
    }

    while (head < tail) {
        cur = &queue[head++];
        for (i = 0; i < 4; i++) {
            next.x = g_direcct[i][0] + cur->x;
            next.y = g_direcct[i][1] + cur->y;
            if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= col) {
                continue;
            }
            if (matrix[next.x][next.y] == 1 && visit[next.x][next.y] == 0) {
                matrix[next.x][next.y] = cur->level + 1;
                queue[tail].x = next.x;
                queue[tail].y = next.y;
                queue[tail].level = cur->level + 1;
                tail++;
                visit[next.x][next.y] = 1;
            }

        }
    }
    for (i = 0; i < row; i++) {
        if (visit[i]) {
            free(visit[i]);
        }
    } 
    if (queue) {
        free(queue);
    }
    *returnSize = matrixSize;
    return matrix;

}
```
### 解题思路
此处撰写解题思路

### 代码

```c
//申请返回值的数组 **ans，将返回值的数组的所有值设置为0
//1.遍历所有节点，将数值为0的x,y push到队列中,非零的值根据x,y将返回值中置为最大值 ans[x][y] = INT_MAX
//队列中取头部x,y; 然后dequeue
//          x,y的四个方向x1,y1如果有效且matrix[x1][y1]为1，如果ans[x1][y1] > (ans[x][y] + 1)，则ans[x1][y1] = ans[x][y] + 1,将x1, y1入队

typedef struct  _pos {
    int x;
    int y;
}Pos;

typedef struct _que {
    int cap;
    int size;
    int head;
    int tail;
    Pos *pos;
}Que;

void QueInit(Que *q, int cap)
{
    if (cap <= 0) {
        printf("cap err\n");
        return;
    }
    q->cap = cap;
    q->size = 0;
    q->head = 0;
    q->tail = -1;
    q->pos = (Pos *)malloc(sizeof(Pos) * cap);
}

void QueEnq(Que *q, int x, int y)
{
    if (q->size == q->cap) {
        printf("que is full\n");
        return;
    }
    q->tail++;
    q->pos[q->tail].x = x;
    q->pos[q->tail].y = y;
    q->size++;
}

void QueDeq(Que *q) 
{
    if (q->size == 0) {
        printf("que is empty\n");
        return;
    }
    q->head++;
    q->size--;
}

void QueHead(Que *q, int *x, int *y)
{
    *x = q->pos[q->head].x;
    *y = q->pos[q->head].y;
}

int QueIsEmpty(Que *q)
{
    return (q->size == 0);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = matrixSize;
    if (matrixSize == 0) { 
        return NULL;
    }
    int row = matrixSize;
    int col = matrixColSize[0];
    int i, j;
    Que q;
    int **ans;
    int *columnSizes;

    columnSizes = (int *)malloc(sizeof(int) * row);
    ans = (int **)malloc(sizeof(int *) * row);

    for (i = 0; i < row; i++) {
        ans[i] = (int *)malloc(sizeof(int) * col);
        memset(ans[i], 0, sizeof(int) * col);
        *(columnSizes + i) = matrixColSize[i];
    }

    *returnColumnSizes = columnSizes;

    QueInit(&q, row * col);

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                QueEnq(&q, i, j);
            } else {
                ans[i][j] = INT_MAX;
            }
        }
    }

    int nb[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int x, y;
    int x1, y1;
    while (!QueIsEmpty(&q)) {
        QueHead(&q, &x, &y);
        QueDeq(&q);
        for (i = 0; i < 4; i++) {
            x1 = x + nb[i][0];
            y1 = y + nb[i][1];
            if (x1 >= 0 && x1 < row && y1 >= 0 && y1 < col && matrix[x1][y1] == 1) {
                if(ans[x1][y1] > ans[x][y] + 1) {
                    ans[x1][y1] = ans[x][y] + 1;
                    QueEnq(&q, x1, y1);
                }
            }
        }
    }
    return ans;
}
```
### 解题思路
典型的BFS，采用数组队列，比较简单

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int x;
    int y;
    int level;
}Queue;
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    if (matrix == NULL || matrixSize <= 0 || matrixColSize == NULL) {
        return NULL;
    }
    int m = matrixSize;
    int n = *matrixColSize;
    int i, j, x, y, xx, yy,level;
    int front = 0;
    int tail = 0;
    int xTmp[4] = {-1, 1, 0, 0};
    int yTmp[4] = {0, 0, -1, 1};
    int** returnMatrix = (int**)malloc(sizeof(int *) * m);
    int *columnSizes = (int *)malloc(sizeof(int) * m);
    
    *returnSize = m;
    for (i = 0; i < m; i++) {
        returnMatrix[i] = (int *)malloc(sizeof(int) * n);
        columnSizes[i] = n;
    }
    *returnColumnSizes = columnSizes;
    Queue *q = (Queue *)malloc(sizeof(Queue) * m * n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                q[tail].x = i;
                q[tail].y = j;
                q[tail].level = 0;
                tail++;
                returnMatrix[i][j] = 0;
            }
        }
    }
    while (front != tail) {
        x = q[front].x;
        y = q[front].y;
        level = q[front++].level;
        for (i = 0; i < 4; i++) {
            xx = x + xTmp[i];
            yy = y + yTmp[i];
            if (xx >= 0 && xx < m && yy >=0 && yy < n && matrix[xx][yy] == 1) {
                matrix[xx][yy] = 2;
                q[tail].x = xx;
                q[tail].y = yy;
                q[tail++].level = level + 1;
                returnMatrix[xx][yy] = level + 1;
                printf("[%d][%d] = %d \n",xx, yy, returnMatrix[xx][yy]);
            }
        }
    }
    //return NULL;
    return returnMatrix;
}
```
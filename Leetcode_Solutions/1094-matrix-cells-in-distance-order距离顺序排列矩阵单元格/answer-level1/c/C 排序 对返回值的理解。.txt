### 解题思路
思路很简单，先排序然后按照要求组建一个数组。
但是题目的返回值比较难以捉摸。
首先是*returnSize，按照注释，这个意思好像是要返回一个装了很多数组的（an array of arrays）数组的尺寸（size）,好像是这个断句的吧...
然后是int** returnColumnSizes，很多个小数组的尺寸（The sizes of the arrays）被返回，以一个数组的形式（*returnColumnSizes），说明*returnColumnSizes是一个数组，此数组描述了多个小数组的尺寸。returnColumnSizes是一个指针，指向了指向描述小数组尺寸的数组的指针。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #define ERR 1
 #define OK 0
//定义一个结构体，保存距离和坐标
struct Node {
   int x;
   int y;
   int distance; 
};

void setDistance(struct Node* node, int r0, int c0) {
    int distance = abs(node->x - r0) + abs(node->y - c0);
    node->distance = distance;
    return;
}

int cmp(const void *a, const void *b)
{
    //return ((struct Node *)a)->distance - ((struct Node *)b)->distance;
    return (*(struct Node *)a).distance - (*(struct Node *)b).distance;
}

int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    if ((R == 0) || (C == 0)) {
        return NULL;
    }
    if ((r0 > R) || (r0 < 0)) {
        return NULL;
    }
    if ((c0 > C) || (c0 < 0)) {
        return NULL;
    }

    struct Node * nodeArray = (struct Node *)malloc(sizeof(struct Node) * R * C);
    memset(nodeArray, 0, sizeof(struct Node) * R * C);
    struct Node * nodeArrayTmp = nodeArray;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            nodeArrayTmp->x = i;
            nodeArrayTmp->y = j;
            setDistance(nodeArrayTmp, r0, c0);
            nodeArrayTmp++;
        }
    }

    //从小到大排序。
    qsort(nodeArray, R * C, sizeof(struct Node), cmp);
    struct Node * nodeArrayTmp1 = nodeArray;
    for (int i = 0; i < R*C; i++) {
        nodeArrayTmp1++;
    }

    int **matrix = (int **)malloc(sizeof(int *) * R * C);
    memset(matrix, 0, sizeof(int *) * R * C);

    int **matrixTmp = matrix;
    nodeArrayTmp = nodeArray;

    for(int j = 0; j < R * C; j++) {
        *matrixTmp = (int *)malloc(sizeof(int) * 2);
        memset(*matrixTmp, 0, sizeof(int) * 2);
        *(*matrixTmp + 0) = nodeArrayTmp->x;
        *(*matrixTmp + 1) = nodeArrayTmp->y;
        nodeArrayTmp++;
        matrixTmp++;
    }

    *returnSize = R * C;
    int* arr = (int*)malloc(sizeof(int) * R * C);
    for (int i = 0; i < R * C; i++) {
        *(arr + i) = 2;
    }
    *returnColumnSizes = arr;

    free(nodeArray);

    return matrix;
}
```
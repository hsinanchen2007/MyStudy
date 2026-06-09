### 解题思路
组织一个数组用来记录每个points的下标和值，排序，输出前k个元素。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int Compare(const void *a, const void *b)
{/*
    int *pa = *(int**)a;
    int *pb = *(int**)b;

    return pa[1] - pb[1];
*/
    return ((int*)a)[1] - ((int*)b)[1];
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    int **retArr = NULL;
    int tmpArr[10000][2] = {{0}};
    //int **tmpArr = NULL;
    *returnSize = K;

    if (pointsSize < 1) {
        return points;
    }

    retArr = (int**)malloc(pointsSize * sizeof(int*));
    //tmpArr = (int**)malloc(pointsSize * sizeof(int*));
    for (int i = 0; i < pointsSize; i++) {
        retArr[i] = (int*)malloc(sizeof(points[0]));
        //tmpArr[i] = (int*)malloc(sizeof(points[0]));
        memset(retArr[i], 0, sizeof(points[0]));

        tmpArr[i][0] = i;
        tmpArr[i][1] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }
    
    qsort(tmpArr, pointsSize, sizeof(retArr[0]), Compare);

    *returnColumnSizes = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        retArr[i][0] = points[tmpArr[i][0]][0];
        retArr[i][1] = points[tmpArr[i][0]][1];
        (*returnColumnSizes)[i] = 2;
    }
    //free(tmpArr);
    return retArr;
}
```
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//二维数组比较大小函数
int cmp(const void* a,const void* b) {
    int* aa = *(int**)a;
    int* bb = *(int**)b;
    if(aa[0] == bb[0]) {
        return aa[0] - bb[0];
    } else {
        return aa[1] - bb[1];
    }
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    //特殊情况判断
    if(points == NULL || pointsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int Row = pointsSize;
    int Col = *pointsColSize;
    //res数组用于保存每个点的平方值以及索引
    int** res = (int**)malloc(sizeof(int*) * Row);
    for(int i = 0;i < Row;i++) {
        res[i] = malloc(sizeof(int) * Col);
    }
    //rslt数组用于保存最终排序后的点，以及索引
    int** rslt = (int**)malloc(sizeof(int*) * Row);
    for(int i = 0;i < Row;i++) {
        rslt[i] = malloc(sizeof(int) * Col);
    }
    //保存索引和平方值
    for(int i = 0;i < Row;i++) {
        res[i][0] = i;
        res[i][1] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }
    //按照平方值进行排序
    qsort(res,Row,sizeof(res[0]),cmp);
    //用rlst数组进行保存
    for(int i = 0;i < K;i++) {
        rslt[i][0] = points[res[i][0]][0];
        rslt[i][1] = points[res[i][0]][1];
    }
    //返回参数处理
    *returnSize = K;
    *returnColumnSizes = malloc(sizeof(int) * K);//sizeof(int)而不是sizeof(int*)
    for(int i = 0;i < K;i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return rslt;
}

```

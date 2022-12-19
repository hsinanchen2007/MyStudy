


int fun(const void *aa, const void *bb) {
    int *a = *(int **)aa;
    int *b = *(int **)bb;
    return a[0] - b[0];
}
int max(int a, int b) {
    return a > b ? a : b;
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if (intervalsSize == 0 || intervals == NULL) {
        *returnSize = 0;
        return NULL;
    }
    //按照区间左值从小到大排序
    qsort(intervals, intervalsSize, sizeof(int **), fun);
    
    int **arr = malloc(intervalsSize * sizeof(int *));
    int len = *intervalsColSize;
    for (int i = 0; i < intervalsSize; i++) {
        arr[i] = malloc(len * sizeof(int));
        memset(arr[i], 0, len * sizeof(int));
    }
    
    int temp[2] = {0};
    int i = 0;
    int retSize = 0;
    //合并重复的
    while(i < intervalsSize) {
        temp[0] = intervals[i][0];
        temp[1] = intervals[i][1];
        printf("temp[%u %u], ", temp[0], temp[1]);
        if ((i + 1) < (intervalsSize)) {
            while (temp[1] >= intervals[i+1][0] ) { //去重一次后仍旧有重复的区间继续去重直到满足条件
                //选最大的
                temp[1] = max(intervals[i+1][1], temp[1]);
                i++;
                if ((i + 1) >= (intervalsSize)) { //防止越界
                    break;
                }
            }
        }
        i++;
        arr[retSize][0] = temp[0];
        arr[retSize][1] = temp[1];
        retSize++;
    }
    //returnColumnSizes 参数的处理容易出错
    *returnColumnSizes = malloc(sizeof(int) * retSize);
    for(int i = 0;i < retSize;i++) {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = retSize;
    return arr;
}
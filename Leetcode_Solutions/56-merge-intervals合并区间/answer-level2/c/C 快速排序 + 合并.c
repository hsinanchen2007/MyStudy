```
int compare(int** ptr1, int**ptr2)
{
    return (ptr1[0][0] - ptr2[0][0]);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int i;
    int a0, a1;
    int index = 0;
    int **result;

    if (intervals == NULL || intervalsSize < 1 || intervalsColSize == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 对二维数组中的第一个元素进行小->大 排序
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    result = (int **)malloc(sizeof(int*) * intervalsSize);

    for (i = 0 ; i < intervalsSize; i++) {
        result[i] = (int *)malloc(sizeof(int) * (*intervalsColSize));
    }

    result[index][0] =  intervals[0][0];
    result[index][1] =  intervals[0][1];

    for (i = 1; i < intervalsSize; i++) {
        a0 = intervals[i][0];
        a1 = intervals[i][1];

        if (a0 >= result[index][0] && a0 <= result[index][1] && a1 > result[index][1]) {
            result[index][1] = a1;            // 合并
        } else if (a0 > result[index][1]) {   // 新增
            index++;
            result[index][0] =  intervals[i][0];
            result[index][1] =  intervals[i][1];
        } 
    }

    *returnSize = ++index;
    *returnColumnSizes = (int *)malloc(sizeof(int) * index);
    for (i = 0; i < index; i++) {
        (*returnColumnSizes)[i] = 2; 
    }

    return result;
}
```

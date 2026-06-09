### 解题思路
根据开始区间 如果开始区间一样，根据结束区间拍完顺序后，下一组开始和上一组结束比较，确认是合并还是新生成一组。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(void* a, void* b) {
    int* a1 = *(int** )a;
    int* b1 = *(int** )b;
    if (a1[0] == b1[0]) {
        return a1[1] - b1[1];
    } else {
        return a1[0] - b1[0];
    }
 }
#define MAX(a, b) ((a) > (b) ? (a) :(b))
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){

    int** ret = NULL;
    int index = 0;
    *returnColumnSizes = (int*)malloc(intervalsSize* sizeof(int));

    ret = (int**)malloc(intervalsSize * (sizeof(int*)));
    if (intervalsSize == 0 || intervals == NULL) {
        *returnSize = intervalsSize;
        return intervals;
    }

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    ret[index] = malloc(sizeof(int)*2);
    ret[index][0] = intervals[0][0];
    ret[index][1] = intervals[0][1]; 
    index++;   
    for (int i = 1; i < intervalsSize; i++ ) {
        if (intervals[i][0] > ret[index-1][1]) {
            ret[index] = malloc(sizeof(int)*2);
            ret[index][0] = intervals[i][0];
            ret[index][1] = intervals[i][1]; 
            index++;
        } else {
            ret[index-1][1] = MAX(intervals[i][1],ret[index-1][1]);
        }
    }
    for (int i = 0; i < index; i++) {
         (*returnColumnSizes)[i] = 2;
    }
    *returnSize = index;
    return ret;
}
```
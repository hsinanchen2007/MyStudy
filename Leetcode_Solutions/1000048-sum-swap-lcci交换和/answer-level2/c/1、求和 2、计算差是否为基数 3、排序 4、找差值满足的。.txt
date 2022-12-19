# 1、求和 2、计算差是否为基数 3、排序 4、找差值满足的。

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *p1, const void *p2){
    const int a = *(int *)p1;
    const int b = *(int *)p2;
    return a > b ? 1 : -1;
}
int* findSwapValues(int* array1, int array1Size, int* array2, int array2Size, int* returnSize){
    *returnSize = 0;
    if (array1 == NULL || array2 == NULL || array1Size < 1 || array2Size < 1) {
        return NULL;
    }
    int sum1 = 0;
    int sum2 = 0;
    int i = 0;
    while (i < array1Size || i < array2Size) {
        if (i < array1Size) {
            sum1 += array1[i];
        }
        if (i < array2Size) {
            sum2 += array2[i];
        }
        i++;
    }
    if (abs(sum1 - sum2) % 2 == 1) {
        return NULL;
    }
    qsort(array1, array1Size, sizeof(int), cmp);
    qsort(array2, array2Size, sizeof(int), cmp);
    i = 0;
    int j = 0;
    while (i < array1Size && j < array2Size) {
        if (sum1 - array1[i] + array2[j] == sum2 + array1[i] - array2[j]) {
            *returnSize = 2;
            int *result = (int *)malloc(*returnSize  * sizeof(int));
            result[0] = array1[i];
            result[1] = array2[j];
            return result;
        }else if (sum1 - array1[i] + array2[j] > sum2 + array1[i] - array2[j]) {
            i++;
        }else {
            j++;
        }
    }
    return NULL;
}

/*
int cmp(const void *p1, const void *p2){
    const int a = *(int *)p1;
    const int b = *(int *)p2;
    return a > b ? 1 : -1;
}
int* findSwapValues(int* array1, int array1Size, int* array2, int array2Size, int* returnSize){
    *returnSize = 0;
    if (array1 == NULL || array2 == NULL || array1Size < 1 || array2Size < 1) {
        return NULL;
    }
    int sum1 = 0;
    for (int i = 0; i < array1Size; i++) {
        sum1 += array1[i];
    }
    int sum2 = 0;
    for (int i = 0; i < array2Size; i++) {
        sum2 += array2[i];
    }
    int sub = 0;
    if (sum1 > sum2) {
        sub = sum1 - sum2;
    }else {
        sub = sum2 - sum1;
    }
    if (sub % 2 == 1) {
        printf("jishu");
        return NULL;
    }
    sub = sub /2;
    qsort(array1, array1Size, sizeof(int), cmp);
    qsort(array2, array2Size, sizeof(int), cmp);
    int i = 0;
    int j = 0;
    while (i < array1Size && j < array2Size) {
        if (sum1 >= sum2) {
            if (array1[i] - array2[j] == sub) {
                *returnSize = 2;
                int *result = (int *)malloc(*returnSize  * sizeof(int));
                result[0] = array1[i];
                result[1] = array2[j];
                return result;
            }else if (array1[i] - array2[j] < sub) {
                i++;
            }else {
                j++;
            }
        }else {
            if (array2[j] - array1[i] == sub) {
                *returnSize = 2;
                int *result = (int *)malloc(*returnSize  * sizeof(int));
                result[0] = array1[i];
                result[1] = array2[j];
                return result;
            }else if (array2[j] - array1[i] < sub) {
                j++;
            }else {
                i++;
            }
        }
    }
    return NULL;
}
*/
```

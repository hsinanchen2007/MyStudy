```
int CompareInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int **minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes)
{
    if (!arr || arrSize < 2) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int **res = malloc(100 * 1024 * sizeof(int *));
    int cow = 0;
    int diff = INT_MAX;

    qsort(arr, arrSize, sizeof(int), CompareInt);
    for (int i = 0; i < arrSize - 1; i++) {
        int temp = fabs(arr[i] - arr[i + 1]);
        if (temp < diff) {
            diff = temp;
        }
    }
    for (int i = 0; i < arrSize - 1; i++) {
        int temp = fabs(arr[i] - arr[i + 1]);
        if (temp == diff) {
            res[cow] = malloc(2 * sizeof(int));
            res[cow][0] = arr[i];
            res[cow][1] = arr[i + 1];
            cow++;
        }
    }
    int *retColSize = malloc(cow * sizeof(int));

    for (int i = 0; i < cow; i++) {
        retColSize[i] = 2;
    }
    *returnColumnSizes = retColSize;
    *returnSize = cow;
    return res;
}
```

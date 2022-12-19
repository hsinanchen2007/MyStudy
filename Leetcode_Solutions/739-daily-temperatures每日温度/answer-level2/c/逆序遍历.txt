从数组右侧向左侧遍历，基于右侧已知数据，减少当前查找比较次数。
```
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int  i;
    int  j;
    int *returnArr = (int *)malloc(sizeof(int) * TSize);
    if (returnArr == NULL) {
        return NULL;
    }
    memset(returnArr, 0, sizeof(int) * TSize);

    for (i = TSize - 2; i >= 0; i--) {
        for (j = i + 1; j < TSize; j += returnArr[j]) {
            if (T[j] > T[i]) {
                returnArr[i] = j - i;
                break;
            } else if (returnArr[j] == 0) {
                returnArr[i] = 0;
                break;
            }
        }
    }
    *returnSize = TSize;
    return returnArr;
}
```

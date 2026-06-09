# 用数组按保存取模的计数

```
int numPairsDivisibleBy60(int* time, int timeSize){
    int *arry = (int *)malloc(60 * sizeof(int));
    memset(arry, 0, 60 * sizeof(int));
    for (int i = 0; i < timeSize; i++) {
        arry[time[i] % 60]++;
    }
    int sum = 0;
    if (arry[0] > 1) {
        sum = sum +  arry[0] * (arry[0] - 1) / 2;
    }
    if (arry[30] > 1) {
        sum = sum + arry[30] * (arry[30] - 1) / 2;
    }
    for (int i = 1; i < 30; i++) {
        sum = sum + arry[i] * arry[60 - i];
    }
    free(arry);
    arry = NULL;
    return sum;
}
```

```
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *stk = (int *) malloc(sizeof(int) * TSize);
    int *res = (int *) malloc(sizeof(int) * TSize);
    int top = -1;
    for (int i = TSize - 1; i >= 0; i--) {
        while (top != -1 && T[stk[top]] <= T[i]) top--;
        if (top == -1) res[i] = 0;
        else res[i] = stk[top] - i;
        stk[++top] = i;
    }
    free(stk);
    *returnSize = TSize;
    return res;
}
```

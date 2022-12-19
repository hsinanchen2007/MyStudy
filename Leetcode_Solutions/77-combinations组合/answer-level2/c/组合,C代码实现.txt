typedef struct MyStruct
{
    int *nums;
    int idx;
}MStack;
// 求阶乘
int CmbCalc(int n, int k)
{
    int j = 1;
    int val = 1;
    if (k <=0) {
        return 1;
    }
    for (size_t i = k + 1; i <= n; i++) {
        val = val * i / j;
        j++;
    }
    return val;
}

void push(MStack *pStack, int val) {
    pStack->nums[pStack->idx++] = val;
}

void pop(MStack *pStack) {
    pStack->idx--;
}

void track(int **ret, int n, int k, int* returnSize, MStack *pStack, int idx)
{
    if (pStack->idx == k) {
        for (size_t j = 0; j < k; j++) {
            (ret[(*returnSize)])[j] = pStack->nums[j];
        }
        (*returnSize)++;
        return;
    }
    for (size_t i = idx; i <= n; i++) {
        push(pStack, i);
        track(ret, n, k, returnSize, pStack, i + 1);
        pop(pStack);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int row = CmbCalc(n, k);
    *returnColumnSizes = malloc(sizeof(int) * row);
    *returnSize = 0;
    int **ret;
    ret = malloc(sizeof(int *) * row);
    MStack tempStack;
    tempStack.nums = malloc(sizeof(int) * k);
    tempStack.idx = 0;

    for (size_t i = 0; i < row; i++){
        (*returnColumnSizes)[i] = k;
        ret[i] = (int*)malloc(sizeof(int) * k);
    }
    track(ret, n, k, returnSize, &tempStack, 1);
    free(tempStack.nums);
    return ret;
}
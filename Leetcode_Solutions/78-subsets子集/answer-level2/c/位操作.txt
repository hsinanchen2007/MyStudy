![image.png](https://pic.leetcode-cn.com/c47812b7c408a77540fe792cda4791513d2e62e5dfc44d2323da23f9ed0dc823-image.png)




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int CmbCalc(int n, int k)
{
    int j = 1;
    int val = 1;
    if (k <= 0) {
        return 1;
    }
    for (size_t i = k + 1; i <= n; i++) {
        val = val * i / j;
        j++;
    }
    return val;
}

typedef struct MyStruct
{
    int *nums;
    int idx;
}MStack;
void push(MStack *pStack, int val) {
    pStack->nums[pStack->idx++] = val;
}

int pop(MStack *pStack) {
    pStack->idx--;
    return pStack->nums[pStack->idx];
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ret;
    int i, j;
    int row = 2;
    MStack mStack;
    mStack.nums = malloc(sizeof(int) * numsSize);
    mStack.idx = 0;
    int *flg = malloc(sizeof(int) * numsSize);
    flg[0] = 1;
    for (i = 1; i < numsSize; i++) {
        row += CmbCalc(numsSize, i);
        flg[i] = flg[i - 1] * 2;
    }
    
    *returnSize = row;
    ret = malloc(sizeof(int *) * row);
    (*returnColumnSizes) = malloc(sizeof(int) * row);

    (*returnColumnSizes)[0] = 0;
    ret[0] = NULL;
    for (i = 1; i < row; i++) {
        for (j = 0; j < numsSize; j++) {
            if (flg[j] & i) push(&mStack, nums[j]);
        }
        ret[i] = malloc(sizeof(int) * mStack.idx);
        (*returnColumnSizes)[i] = 0;
        for (int k = 0; k < mStack.idx; k++) {
            ret[i][(*returnColumnSizes)[i]++] = mStack.nums[k];
        }
        mStack.idx = 0;
    }
    free(flg);
    free(mStack.nums);
    return ret;
}
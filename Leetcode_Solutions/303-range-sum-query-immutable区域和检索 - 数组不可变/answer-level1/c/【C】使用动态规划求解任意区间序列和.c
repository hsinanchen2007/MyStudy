1.使用动态规划顺序求解从下表0开始到i的序列和
2.i到j包含i、j点的序列和则为dp[j] - dp[i-1]
```
typedef struct {
    int *dp;
    int numsSize;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize)
{
    if (nums == NULL || numsSize <= 0) {
        return NULL;
    }
    NumArray *numArray = malloc(sizeof(NumArray));
    if (numArray == NULL) {
        return NULL;
    }
    memset(numArray, 0, sizeof(NumArray));

    int *dp = (int *)malloc(sizeof(int) * (numsSize));
    if (dp == NULL) {
        return numArray;
    }

    memset(dp, 0, numsSize);
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        dp[i] = dp[i - 1] + nums[i];
    }

    numArray->dp = dp;
    numArray->numsSize = numsSize;
    return numArray;
}

int numArraySumRange(NumArray* obj, int i, int j)
{
    if (obj == NULL) {
        return 0;
    }
    if (i < 0 || i >= obj->numsSize || j < 0 || j >= obj->numsSize ) {
        return 0;
    }
    if (obj->dp == NULL) {
        return 0;
    }
    if (i == 0) {
        return obj->dp[j];
    }
    return obj->dp[j] - obj->dp[i - 1];
}

void numArrayFree(NumArray* obj)
{
    if (obj == NULL) {
        return 0;
    }
    if (obj->dp != NULL) {
        free(obj->dp);
        obj->dp = NULL;
    }
    free(obj);
    obj = NULL;
}

```

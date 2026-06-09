### 解题思路

暴力搞法，请看代码

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int CompareInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool CheckParam(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    if (!A || !B || ASize != BSize || !returnSize) {
        return false;
    }
    return  true;
}

int Find(int *s, int len, int num)
{
    int res = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] > num) {
            res = s[i];
            s[i] = INT_MIN;
            return res;
        }
    }
    for (int i = 0; i < len; i++) {
        if (s[i] != INT_MIN) {
            res = s[i];
            s[i] = INT_MIN;
            return res;
        }
    }
    return 0;
}

int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    int *res = malloc(ASize * sizeof(int));

    memset(res, 0, ASize * sizeof(int));
    (*returnSize) = 0;
    if (!CheckParam(A, ASize, B, BSize, returnSize)) {
        return NULL;
    }
    qsort(A, ASize, sizeof(int), CompareInt);
    printf("1\n");
    for (int i = 0; i < BSize; i++) {
        res[i] = Find(A, ASize, B[i]);
    }
    (*returnSize) = ASize;
    return res;
}
```
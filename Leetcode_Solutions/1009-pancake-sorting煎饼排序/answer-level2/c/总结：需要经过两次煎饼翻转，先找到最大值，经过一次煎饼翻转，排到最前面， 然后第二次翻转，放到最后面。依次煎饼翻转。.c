
解释
A = [3, 2, 4, 1]
k = 3 [4, 2, 3, 1]
k = 4 [1, 3, 2, 4]
k = 2 [3, 1, 2, 4]
k = 3 [2, 1, 3, 4]
k = 2 [1, 2, 3, 4]
输出: [3, 4, 2, 3, 2]

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int* pancakeSort(int* A, int ASize, int* returnSize)
{
    int *B = (int *)malloc(sizeof(int) * ASize);
    memcpy(B, A, sizeof(int) * ASize);
    //排序
    qsort(B, ASize, sizeof(B[0]), cmp);

    int *res = (int *)malloc(sizeof(int) * 10 * ASize);
    memset(res, 0, sizeof(int) * 10 * ASize);

    int cnt = 0;
    for (int search_len = ASize; search_len > 1; search_len--) {
        if (A[search_len - 1] != B[search_len - 1]) {
            int k = 0;
            for (int i = 0; i < search_len; i++) {
                if (A[i] == B[search_len - 1]) {
                    k = i + 1;
                    break;
                }
            }
            //第一次煎饼翻转
            for (int i = 0; i < k / 2; i++) {
                int temp = A[i];
                A[i] = A[k - i - 1];
                A[k - i - 1] = temp;
            }
            if (k > 1)
                res[cnt++] = k;
            //第二次煎饼翻转
            for (int i = 0; i < search_len / 2; i++) {
                int temp = A[i];
                A[i] = A[search_len - i - 1];
                A[search_len - i - 1] = temp;
            }
            res[cnt++] = search_len;
        }
    }
    *returnSize = cnt;
    
    return res;
}
```


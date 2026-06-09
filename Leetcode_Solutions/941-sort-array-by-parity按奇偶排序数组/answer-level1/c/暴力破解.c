### 解题思路
此处撰写解题思路
1.申请3个数组
2.前两个分别保存偶数和奇数。
3.分别把偶数和奇数存放到返回的数组中。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *new_A, *new_B, *returnnum;
    int i, j, k, l;
    if (A == NULL) {
        * returnSize = 0;
        return NULL;
    }
    printf("ASize=%d\n", ASize);
    new_A = (int *)malloc(sizeof(int) * ASize);
    new_B = (int *)malloc(sizeof(int) * ASize);
    returnnum = (int *)malloc(sizeof(int) * ASize);
    for (i = 0, j = 0, k = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            new_A[j] = A[i];
            j++;
        } else {
            new_B[k] = A[i];
            k++;
        }
    }
    l = 0;
    for (i = 0; i < j; i++) {
        returnnum[l++] = new_A[i];
    }

    for (i = 0; i < k; i++) {
        returnnum[l++] = new_B[i];
    }
    * returnSize = l;

    free(new_A);
    new_A = NULL;
    free(new_B);
    new_B = NULL;
    return returnnum;
}
```
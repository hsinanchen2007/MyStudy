### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int sum, len_K, len, pa, pk;
    int * res;

    if(K == 0)
    {
        *returnSize = ASize;
        return A;
    }

    len_K = log10(K) + 1;
    *returnSize = (ASize > len_K) ? ASize + 1: len_K + 1;
    res = (int *) malloc(*returnSize * sizeof(int));
    len = *returnSize;
    while(len - 1 >= 1 || K > 0)
    {
       if(ASize > 0) K += A[--ASize];
       res[--len] = K % 10;
       K /= 10;
    }
    
    *returnSize -= len;
    return res + len;
    
}
```
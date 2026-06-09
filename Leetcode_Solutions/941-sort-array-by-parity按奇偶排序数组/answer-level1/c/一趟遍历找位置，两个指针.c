```
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize = ASize;  // 一趟遍历完成，少去复杂的步骤
    int m = 0, i;  // m代表着偶数可以交换的位置
    int tmp;
    for (i = 0; i < ASize; i++)
    {
        if (A[i] % 2 == 0)
        {
            tmp = A[m];
            A[m++] = A[i];
            A[i] = tmp;
        }
    }
    return A;
}
```

### 解题思路
纯C

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int* pRes = (int*)malloc((rowIndex + 1) * sizeof(int));
    memset(pRes, 0, (rowIndex + 1) * sizeof(int));
    int row = 0;
    int col = 0;
    pRes[0] = 1;
    *returnSize = rowIndex + 1;

    for (row = 0; row <= rowIndex; row++)
    {
        for (col = row; 1 <= col; col--)
        {
            pRes[col] = pRes[col] + pRes[col - 1];
        }
    }

    return pRes;
}
```
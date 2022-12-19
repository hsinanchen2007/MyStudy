### 解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int i, j;
    *returnSize = rowIndex + 1;
    int *arr = (int *)malloc(sizeof(int) * (rowIndex + 1));
    memset(arr, 0x0, sizeof(int) * (rowIndex + 1));
    for (i = 0; i <= rowIndex; i++)
    {
        arr[i]++;
        for (j = i - 1; j > 0; j--) arr[j] += arr[j - 1];
    }
    return arr;
}
```
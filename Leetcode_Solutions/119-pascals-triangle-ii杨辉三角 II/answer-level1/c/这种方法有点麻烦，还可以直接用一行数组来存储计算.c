### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    *returnSize = 1 + rowIndex;
    int ** arr = (int**)malloc(sizeof(int*) * (rowIndex +1));
    int q = 0;
     for(int i = 0; i < rowIndex + 1; ++i)
    {
        arr[i] = (int*)malloc(sizeof(int) * (i+ 1));
            arr[i][0] = 1;
            arr[i][i] = 1;
        for(int j = 1; j < i; ++j)
        {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];            
        }
         q = i;
    }
    int *a = (int*)malloc(sizeof(int) * (rowIndex+1));   //用a去存要求输出的那一行
    for(int i = 0; i < rowIndex + 1; ++i)
        a[i] = arr[q][i];
        
    return a;
}
```
### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){
    int *outArr = NULL;
    int clc = 1000000000;
    *returnSize = cellsSize;
    if (N <= 0 || cellsSize <= 3) {
        return cells;
    }
    
    outArr = (int*)malloc(cellsSize * sizeof(int));
    memset(outArr, 0, cellsSize*sizeof(int));

    for (int i = 1; i <= (N % 14 + 14); i++) {
        for (int p = 1; p < cellsSize-1; p++) {
            if (i % 2 != 0) {
                if ((cells[p-1] == 0 && cells[p+1] == 0) || (cells[p-1] == 1 && cells[p+1] == 1)) {
                    outArr[p] = 1;
                } else {
                    outArr[p] = 0; 
                }             
            } else {
                if ((outArr[p-1] == 0 && outArr[p+1] == 0) || (outArr[p-1] == 1 && outArr[p+1] == 1)) {
                    cells[p] = 1;
                } else {
                    cells[p] = 0; 
                }
            }
        }
        if(i%2 != 0)
            memset(cells, 0, cellsSize*sizeof(int));
        else
            memset(outArr, 0, cellsSize*sizeof(int));       
    }
    return N % 2 == 0 ? cells : outArr;
}
```
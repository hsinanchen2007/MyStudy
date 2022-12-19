### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX 65
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){

    if(cells == NULL || cellsSize == 0) {
        *returnSize =0;
        return NULL;
    }
    int temp[MAX+1][8] = {0};
    int tempindex[MAX+1] = {0};
    int *result = NULL;
    result = (int *)malloc(cellsSize * sizeof(int));
    memset(result,0,cellsSize * sizeof(int));
    *returnSize = cellsSize;
    for (int i=0; i < 8; i++) {
        temp[0][i] = cells[i];
    }
    for (int i=1; i <= MAX; i++) {
        for (int j=1; j < 7; j++) {
            if (temp[i-1][j-1] == temp[i-1][j+1]) {
               temp[i][j] = 1; 
            } else {
                temp[i][j] = 0;   
            }
            tempindex[i] = (tempindex[i] * 2) + temp[i][j];
        }
    }
    if (N <= (MAX-1)) {
            for (int i=0; i < 8; i++) {
                result[i] = temp[N][i];
            }
        return result;
    }
    int flag =0;
    for (int i=1; i< MAX; i++) {
        if (tempindex[MAX] == tempindex[i]) {
            flag = i;
            break;
        }
    }
    int div = MAX-flag;
    div = N%div;
    for (int i=0; i < 8; i++) {
        result[i] = temp[div][i];
    }
        return result;
}
```
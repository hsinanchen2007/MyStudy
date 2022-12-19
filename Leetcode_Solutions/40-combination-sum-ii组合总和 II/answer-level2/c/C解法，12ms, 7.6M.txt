```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int g_out[100][100] = {0};
int tmp[100] = {0};

void sort(int *input, int size) 
{
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (input[j + 1] < input[j]) {
                tmp = input[j + 1];
                input[j + 1] = input[j];
                input[j] = tmp;
            }
        }
    }
}

void CalcOut(int *remainC, int remainSize, int remainT, int *row, int *col, int tmpCol)
{
    for (int i = 0; i < remainSize; i++) {
        int colSize = tmpCol;
        if (i > 0) {
            if (remainC[i] == remainC[i - 1]) {
                continue;   // 对于重复的数就直接跳过即可
            }
        }        
        if (remainC[i] <= remainT) {
            tmp[colSize] = remainC[i];
            colSize++;
            if (remainC[i] == remainT) {
                memcpy(g_out[*row], tmp, colSize * sizeof(int));
                col[*row] = colSize;
                (*row)++;
                continue;
            }
            CalcOut(remainC + i + 1, remainSize - i - 1, remainT - remainC[i], row, col, colSize);
        }
    }    
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    if (candidates == NULL) {
        return NULL;
    }
    /* 先将结果从小到大排序 */
    sort(candidates, candidatesSize);
    int outNum = 0;
    int col[100] = {0};
    /* DFS，将OK的结果放到全局变量中 */
    CalcOut(candidates, candidatesSize, target, &outNum, col, 0);
    int **output = (int **)malloc(outNum * sizeof(int *));
    *returnSize = outNum;
    returnColumnSizes[0] = (int *)malloc(outNum * sizeof(int));
    for (int i = 0; i < outNum; i++) {
        output[i] = (int *)malloc(col[i] * sizeof(int));
        returnColumnSizes[0][i] = col[i];
        for (int j = 0; j < col[i]; j++) {
            output[i][j] = g_out[i][j];
        }
    }
    return output;
}


```

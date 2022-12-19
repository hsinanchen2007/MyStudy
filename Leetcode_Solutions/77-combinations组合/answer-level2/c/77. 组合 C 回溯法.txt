## 回溯模板
```
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```
## 代码
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int stack[10000];
int top = -1;

void backtrace(int n, int k, int start, int** result, int* resultSize, int *resultColSize){
    if (top == k - 1) {
        int *temp = (int*)malloc(sizeof(int) * k);
        memset(temp, 0, sizeof(int) * k);
        for (int i = 0; i <= top; i++) {
            temp[i] = stack[i];
        }

        result[resultSize[0]] = temp;
        resultColSize[resultSize[0]] = k;
        resultSize[0]++;

        return;
    }

    for (int j = start; j <= n; j++) {
        stack[++top] = j;
        backtrace(n, k, j + 1, result, resultSize, resultColSize);
        top--;
    }

    return;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){

    int **result = NULL;

    if (n == 0 || k <= 0) {
        returnSize[0] = 0;
        *returnColumnSizes = NULL;
        return result;
    } 
    
    int start = 1;

    result = (int**)malloc(sizeof(int) * 10000);
    int resultSize = 0;
    int *resultColSize = (int*)malloc(sizeof(int) * 10000);

    backtrace(n, k, start, result, &resultSize, resultColSize);

    *returnColumnSizes = resultColSize;
    returnSize[0] = resultSize;
    return result;
}
```
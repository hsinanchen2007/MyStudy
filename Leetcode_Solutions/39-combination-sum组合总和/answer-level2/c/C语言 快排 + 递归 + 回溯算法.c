代码：
    #define MAX_RES_SIZE    500
#define MAX_COLUMN_SIZE 100

int Comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void AddToRes(int **res, int *resIndex, int *resColumnSize, int *arr, int size)
{
    int i;

    res[*resIndex] = (int *)malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        res[*resIndex][i] = arr[i];
    }    
    resColumnSize[*resIndex] = size;

    (*resIndex)++;

    return;
}

void BackTrace(int target, int *candidates, int candidatesSize, int index, int *arr, int arrIndex, int **res, int *resIndex, int *resColumnSize)
{
    int i;

    for (i = index; i < candidatesSize; i++) {
        if (candidates[i] > target) {
            break;
        }
        arr[arrIndex] = candidates[i];
        if (candidates[i] == target) {            
            AddToRes(res, resIndex, resColumnSize, arr, arrIndex + 1);
        } else {
            BackTrace(target - candidates[i], candidates, candidatesSize, i, arr, arrIndex + 1, res, resIndex, resColumnSize);
        }
    }

    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int *arr = NULL;
    int **res = NULL;
    int *columnSize = NULL;

    arr = (int *)malloc(sizeof(int) * MAX_COLUMN_SIZE);
    memset(arr, 0, sizeof(int) * MAX_COLUMN_SIZE);

    res = (int **)malloc(sizeof(int *) * MAX_RES_SIZE);
    memset(res, 0, sizeof(int *) * MAX_RES_SIZE);

    columnSize = (int *)malloc(sizeof(int) * MAX_RES_SIZE);
    memset(columnSize, 0, sizeof(int) * MAX_RES_SIZE);

    *returnSize = 0;
    *returnColumnSizes = columnSize;

    qsort(candidates, candidatesSize, sizeof(candidates[0]), Comp);

    BackTrace(target, candidates, candidatesSize, 0, arr, 0, res, returnSize, columnSize);

    free(arr);

    return res;
}

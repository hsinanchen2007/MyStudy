```
#define MAXSIZE 1000

int Cmp(const void *a, const void *b)
{
    if ((*(int **)a)[0] != (*(int **)b)[0]) {
        return (*(int **)a)[0] - (*(int **)b)[0];
    } else {
        return (*(int **)b)[1] - (*(int **)a)[1];
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** highFive(int** items, int itemsSize, int* itemsColSize, int* returnSize, int** returnColumnSizes){
    int i;
    qsort(items, itemsSize, sizeof(items[0]), Cmp);
    int **returnVal = (int **)malloc(MAXSIZE * sizeof(int *));
    *returnSize = 0;
    int oldVal = 0;
    int j;
    for (i = 0; i < itemsSize; i++) {
        if (items[i][0] != oldVal) {
            returnVal[*returnSize] = (int *)malloc(2 * sizeof(int));
            returnVal[*returnSize][0] = 0;
            returnVal[*returnSize][1] = 0;
            returnVal[*returnSize][0] = items[i][0];
            for (j = i; j < i + 5; j++) {
                returnVal[*returnSize][1] += items[j][1];
            }
            returnVal[*returnSize][1] = returnVal[*returnSize][1] / 5;
            oldVal = returnVal[*returnSize][0];
            (*returnSize)++;
            i = i + 4;
        }
    }
    (*returnColumnSizes) = (int *)malloc((*returnSize) * sizeof(int));
    for (i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return returnVal;
}
```

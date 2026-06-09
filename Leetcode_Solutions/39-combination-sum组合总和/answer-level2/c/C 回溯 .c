```

void backTrace(int *candidates, int candidatesSize, int target, int* returnSize, int* returnColumnSizes, int fromIndex, int sum, int **ret, int *path, int depth)
{
    if(sum == target)
    {
        int index = (*returnSize)++;
        ret[index] = malloc(sizeof(int) * depth);
        memcpy(ret[index], path, sizeof(int) * depth);
        returnColumnSizes[index] = depth;
    }
    else if(sum > target) return;

    // sum < target
    for(int i = fromIndex; i < candidatesSize; i++)
    {
        int num = candidates[i];

        path[depth] = num;
        sum += num;
        backTrace(candidates, candidatesSize, target, returnSize, returnColumnSizes, i, sum, ret, path, depth + 1);
        sum -= num;
    }
}

#define MAX_LEN 1000

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

    *returnSize = 0;

    if(candidatesSize == 0) return NULL;

    int **ret = malloc(sizeof(int *) * MAX_LEN);
    *returnColumnSizes = malloc(sizeof(int) * MAX_LEN);

    int *path = malloc(sizeof(int *) * MAX_LEN);

    backTrace(candidates, candidatesSize, target, returnSize, *returnColumnSizes, 0, 0, ret, path, 0);

    free(path);

    return ret;
}
```

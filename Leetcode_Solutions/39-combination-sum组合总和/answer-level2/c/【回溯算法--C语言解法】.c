```
#include <stdlib.h>

int backtrace(int* candidates, int candidatesSize, int **outputArrays, int *outputSize, int *outputColums, int *cache, int cacheSize, int target, int start)
{
    for (int i = start; i < candidatesSize; i++) {
        int  a = candidates[i];
        int  mcount = cacheSize + 1;
        int *mcache = (int*)malloc(mcount* sizeof(int));
        if (cache && mcache)
            memcpy(mcache, cache, (mcount - 1) * sizeof(int));
        mcache[mcount - 1] = a;

        if (candidates[i] < target) {
            backtrace(candidates, candidatesSize, outputArrays, outputSize, outputColums, mcache, mcount, target - a, i);
        }
        else if (candidates[i] == target) {
            outputArrays[*outputSize] = mcache;
            outputColums[*outputSize] = mcount;
            (*outputSize)++;
        }
    }

    return 0;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int*  caches = NULL;
    int** outputArrays = (int**)malloc(1000 * sizeof(int));
    int*  outputColums = (int* )malloc(1000 * sizeof(int));

    int outputSize = 0;
    int cachesSize = 0;
    backtrace(candidates, candidatesSize, outputArrays, &outputSize, outputColums, caches, cachesSize, target, 0);

    *returnSize = outputSize;
    *returnColumnSizes = outputColums;

    return outputArrays;
}
```

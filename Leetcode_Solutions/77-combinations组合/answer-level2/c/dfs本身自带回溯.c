```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_LEN 1000
void dfs(int start, int n, int k, int *path, int depth, int **res, int *count) {
    if (k == depth) {
        int *result = (int*)malloc(sizeof(int) * k);
        memset(result, 0, sizeof(int) * k);
        memcpy(result, path, sizeof(int) * k);
        res[(*count)++] = result;
        return;
    }

    for (int i = start; i <= n; i++) {
        path[depth] = i;
        dfs(i + 1, n, k, path, depth + 1, res, count);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    if (k == 0) {
        return NULL;
    }
    long long size = 1;
    long long mul = 1;
    for(int i = 0; i < k; i++) {
        size *= n - i;
        mul *= (i + 1);
    }
    size = size / mul;
    int *retColSize = (int*) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        retColSize[i] = k; 
    }
    *returnColumnSizes = retColSize;

    int marked[MAX_LEN] = {0};
    int path[MAX_LEN] = {0};

    int **result = (int**) malloc(sizeof(int*) * size);

    int count = 0;
    dfs(1, n, k, path, 0, result, &count);
    *returnSize = size;
    //*returnColumnSizes = numsSize;
    return result;
}
```

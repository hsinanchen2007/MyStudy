```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **multiply(int **a, int ar, int *ac, int **b, int br, int *bc, int *row, int **col)
{
    *row = ar;
    *col = malloc(*row * sizeof(int));
    assert(*col != NULL);
    int **arr = malloc(*row * sizeof(int *));
    assert(arr != NULL);
    for (int i = 0; i < ar; i++) {
        (*col)[i] = *bc;
        arr[i] = malloc(*bc * sizeof(int));
        assert(arr[i] != NULL);
        memset(arr[i], 0, *bc * sizeof(int));
        for (int j = 0; j < *ac; j++) {
            if (a[i][j] == 0)
                continue;
            for (int k = 0; k < *bc; k++)
                arr[i][k] += a[i][j] * b[j][k];
        }
    }
    return arr;
}
```

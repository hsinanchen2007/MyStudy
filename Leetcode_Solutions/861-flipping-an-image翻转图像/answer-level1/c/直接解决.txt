```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int rev(int x)
{
    if (x == 0) {
        return 1;
    } else {
        return 0;
    }
}

int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int i,j;
    int middle;
    *returnSize = ASize;
    *returnColumnSizes = AColSize;
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < AColSize[i]/2; j++) {
            middle = A[i][j];
            A[i][j] = A[i][AColSize[i] - 1 - j];
            A[i][AColSize[i] - 1 - j] = middle;
        }
        for (j = 0; j< AColSize[i];j++) {
            A[i][j] = rev(A[i][j]);
        }
    }
    return A;
}
```

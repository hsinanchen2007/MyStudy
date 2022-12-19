```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize){
    int numSize = (int)pow(10, n) - 1;

    printf("%d ", numSize);
    int* arr = (int *)malloc(sizeof(int) * numSize);
    for (int i = 0; i < numSize; i++) {
        arr[i] = i + 1;
    }

    *returnSize = numSize;
    return arr;
}
```

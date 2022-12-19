# 1、数字可能不是一位。2、动态规划防止超时。

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findLongestSubarray(char** array, int arraySize, int* returnSize){
    *returnSize = 0;
    if (array == NULL || arraySize < 2) {
        return NULL;
    }    
    int start = 0;
    int end = 0;
    int *sums = (int *)malloc((arraySize + 1) * sizeof(int));
    memset(sums, 0, (arraySize + 1) * sizeof(int));
    int *indexs = (int *)malloc((arraySize + 1) * sizeof(int));
    memset(indexs, 0, (arraySize + 1) * sizeof(int));
    for (int i = 0; i < arraySize; i++) {
        indexs[i + 1] = i + 1;
    }
    for (int i = 0; i < arraySize; i++) {
        if (array[i][0] >= '0' && array[i][0] <= '9') {
            sums[i + 1] = sums[i] + 1;
        }else if (toupper(array[i][0]) >= 'A' && toupper(array[i][0]) <= 'Z') {
            sums[i + 1] = sums[i] - 1;
        }        
        if (sums[i + 1] == (i + 1)) {
            continue;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (sums[i + 1] == sums[j]) {
                indexs[i + 1] = indexs[j];
                if ((i + 1 - indexs[i + 1]) > (end - start)) {
                    start = indexs[i + 1];
                    end = i + 1;
                }
                break;
            }
        }
    }
    *returnSize = (end - start);
    free(sums);
    sums = NULL;
    return array + start;
}
```

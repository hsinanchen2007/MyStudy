### 解题思路
先按照字典序排序，再暴力

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int Cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}
char *** suggestedProducts(char ** products, int productsSize, char * searchWord, int* returnSize, int** returnColumnSizes)
{
    qsort(products, productsSize, sizeof(char *), Cmp);
    int len = strlen(searchWord);
    char ***res = (char ***)malloc(len * sizeof(char **));
    int i;
    int *tempSize = (int *)calloc(len, sizeof(int));
    int cnt = 0;
    *returnSize = len;
    *returnColumnSizes = calloc(len, sizeof(int));
    res[0] = malloc(productsSize * sizeof(char *));

    for (i = 0; i < productsSize; i++) {
        if (products[i][0] == searchWord[0]) {
            int temp = strlen(products[i]);
            res[0][tempSize[0]] = calloc(temp + 1, sizeof(char));
            strcpy(res[0][tempSize[0]], products[i]);
            tempSize[0]++;
        }
        if (products[i][0] > searchWord[0]) {
            break;
        }
    }

    for (i = 1; i < len; i++) {
        res[i] = malloc(productsSize * sizeof(char *));
        for (int j = 0; j < tempSize[i - 1]; j++) {
            if(res[i-1][j][i] == searchWord[i]) {
                int temp = strlen(res[i-1][j]);
                res[i][tempSize[i]] = calloc(temp + 1, sizeof(char));
                strcpy(res[i][tempSize[i]], res[i-1][j]);
                tempSize[i]++;
            }
            if (res[i-1][j][i] > searchWord[i]) {
                break;
            }
        }
    }
    for (i = 0; i < len; i++) {
        if (tempSize[i] == 0) {
            break;
        }
       if(tempSize[i] <= 3) {
            returnColumnSizes[0][i] = tempSize[i];
        } else {
            returnColumnSizes[0][i] = 3;
        }
    }
    
    return res;
}
```
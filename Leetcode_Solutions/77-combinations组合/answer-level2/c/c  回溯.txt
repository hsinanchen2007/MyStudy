```
#include <stdio.h>
#include <stdlib.h>
int indexa = 0;
int **combineRecur(int n, int k, int *returnSize, int *Columsize, int **result,int *arry, int num)
{
    if (n == 0 || k == 0  || (n < k)) {
        return 0;
    }
    if (indexa == k) {
        result[*returnSize]  = malloc(sizeof(int)*k);
        memcpy(result[*returnSize], arry, sizeof(int)*k);
        Columsize[*returnSize] = k;
        (*returnSize)++; 
        return 0;   
    }
    for (int i = num; i <= n; i++) {
        arry[indexa++] = i; 
        combineRecur(n, k, returnSize, Columsize, result, arry, i+1);
        indexa--;
    }
    return result;
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int **result = (int**)malloc(sizeof(int*)*10000);
    indexa = 0;
    *returnSize  = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int)*10000);
    int *arry = (int*) malloc(sizeof(int)*k);
    //int arry[2] = {0};
    result = combineRecur(n, k, returnSize, *returnColumnSizes, result,arry, 1);
    return result;
}
```

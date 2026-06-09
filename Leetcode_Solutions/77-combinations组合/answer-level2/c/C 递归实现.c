int **combineRecur(int n, int k, int *returnSize, int *Columsize, int level, int **result,int *arry, int num)
{
    if (n == 0 || k == 0  || (n < k)) {
        return 0;
    }
    if (num > n) {
        return result;
    }
    arry[level] = num;
    if (level == k-1) {
        result[*returnSize]  = malloc(sizeof(int)*k);
        memcpy(result[*returnSize], arry, sizeof(int)*k);
        Columsize[*returnSize] = k;
        (*returnSize)++;    
        return result;
    }
    for (int j = num; j<= n; j++) {
        combineRecur(n, k, returnSize, Columsize,level+1, result, arry, j+1);
    }
    return result;

}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int **result = (int**)malloc(sizeof(int*)*10000);
    *returnSize  = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int)*10000);
    int *arry = (int*) malloc(sizeof(int)*k);
    for (int i = 1; i <= n; i++) {
        result = combineRecur(n, k, returnSize, *returnColumnSizes, 0, result,arry, i);
    }
    return result;
}
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}


int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    qsort(arr,arrSize,sizeof(int),cmp);
    int min = arr[1] - arr[0];
    for (int i = 1; i < arrSize; i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff < min) {
            min = diff;
        }
    }
    
    int ind = 0;
    int maxSize = arrSize;
    int **res = (int **) malloc(sizeof(int *) * maxSize);
    res[ind] = (int*)malloc(sizeof(int) * 2);  
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSize);
    
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == min) {
            res[ind][0] = arr[i - 1];
            res[ind][1] = arr[i];
            (*returnColumnSizes)[ind] = 2;
            ind++;
            res[ind] = (int*)malloc(sizeof(int) * 2);
        } 
    }
    *returnSize = ind;
    return res;
}


int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    int minGap = 10000000;
    int num = 0;
    qsort(arr,arrSize,sizeof(int),cmp);
    int ** re = (int **)malloc(sizeof(int *)*5000);
    for (int j = 0; j < 5000; j++){
        re[j] = (int *)malloc(sizeof(int)*2);
    }
    int * retColSize = (int *)malloc(sizeof(int)*5000);
    for (int i = 0; i < arrSize - 1; i++){
        if (arr[i + 1] - arr[i] < minGap){
            minGap = arr[i + 1] - arr[i];
            num = 1;
            re[0][0] = arr[i];
            re[0][1] = arr[i + 1];
            retColSize[0] = 2;
            
        } else if (arr[i + 1] - arr[i] == minGap){
            re[num][0] = arr[i];
            re[num][1] = arr[i + 1];
            retColSize[num] = 2;
            num++;
        } 
    }
    *returnColumnSizes = retColSize;
    * returnSize = num;
    return re;

}

**# 思路：**
1. 排序
2. 找最小的差
3. 遍历已排序的数组，找符合要求的pairs

# **代码：**
```

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
   
    qsort(arr,arrSize,sizeof(int),cmp);
    int **returnarra = malloc(sizeof(int*)*arrSize), count = 0;
    int *ColumnSizes = (int*)malloc(sizeof(int)* arrSize);
    assert(returnarra!=NULL && ColumnSizes!=NULL);

    int different, min = abs(arr[0]-arr[arrSize-1]);
    for(int i = 1; i < arrSize;i++){
        if((different = abs(arr[i] - arr[i-1])) < min){
            min = different;
        }
    }

    for(int i = 1; i < arrSize; i++){
        different = abs(arr[i] - arr[i-1]);
        if(different == min){
            int *pair = malloc(sizeof(int) * 2);
            pair[0] = arr[i-1];
            pair[1] = arr[i];
            returnarra[count] =pair;
            ColumnSizes[count++] = 2;
        }
    }
    
    *returnSize = count;
    *returnColumnSizes = ColumnSizes;
    return returnarra; 
}
int cmp(const void* num, const void* num2){
    return *(int*)num - *(int*)num2;
}
```

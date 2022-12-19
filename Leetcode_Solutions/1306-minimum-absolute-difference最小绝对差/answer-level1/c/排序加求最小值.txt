先排序， 在求最小值。  然后两两做差相比，输出该二维数组。
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    // qsort
    qsort(arr, arrSize, sizeof(int), cmp);
    int min = INT_MAX;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] < min) {
            min = arr[i] - arr[i - 1];
        }
    }   
    int count = 0;
    for (int i = 1; i < arrSize; i++) { 
        if (arr[i] - arr[i - 1] == min) {
            count++;    
        }
        
    }
    int j = 0;
    int** ans = (int**)malloc(sizeof(int*) * count);
    *returnSize = count;
    *returnColumnSizes = (int *)malloc(sizeof(int)*count);
    for (int i = 1; i < arrSize; i++) { 
        if (arr[i] - arr[i - 1] == min) {
            ans[j] = (int*)malloc(sizeof(int) * 2);
            ans[j][0] = arr[i - 1];
            ans[j][1] = arr[i];
            *(*returnColumnSizes+j) = 2;
            printf("%d %d ", ans[j][0], ans[j][1]);
            j++;    
        }
        
    }
    return ans;
}
```

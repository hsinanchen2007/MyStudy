```
int missingNumber(int* arr, int arrSize){
    if(arr == NULL || arrSize == 0) {
        return 0;
    }
    int k = (arr[arrSize - 1] - arr[0]) / arrSize;
    
    for(int i = 0; i < arrSize - 1; i++) {
        if(arr[i + 1] != (arr[i] + k)) {
            return arr[i] + k;
        }
    }
    return 0;
}
```

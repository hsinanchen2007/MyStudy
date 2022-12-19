```
int* replaceElements(int* arr, int arrSize, int* returnSize){
    if (arrSize == 1){
        arr[0] = -1;
        *returnSize = arrSize;
        return arr;
    }
    if (arrSize == 2){
        arr[0] = arr[1];
        arr[1] = -1;
        *returnSize = arrSize;
        return arr;
    }
    int temp1 = arr[arrSize - 2];
    int temp;
    arr[arrSize - 2] = arr[arrSize - 1];
    for (int i = arrSize - 3; i >= 0; i--){
        temp = arr[i];
        if (temp1 < arr[i + 1]){
            arr[i] = arr[i + 1];
        } else {
            arr[i] = temp1;
        }
        temp1 = temp;
    }
    arr[arrSize - 1] = -1;
    *returnSize = arrSize;
    return arr;
}
```

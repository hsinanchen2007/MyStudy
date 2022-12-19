申请一行的空间，从后往前处理就不需要考虑数组元素被处理时被覆盖的问题。

```
int* getRow(int rowIndex, int* returnSize){
    * returnSize = rowIndex + 1;
    int* array = (int *)malloc(sizeof(int) * (rowIndex+1));
    for(int i=0; i<rowIndex+1; i++){
        array[i]=1;
        for(int j=i-1; j>0; j--) array[j] = array[j] + array[j-1];
        array[0] = 1;
    }
    return array;
}
```


设输入N个数据。从右边起构建数组，时间复杂度为O(N);从左边起构建数组，时间复杂度为O(N^2)。
```c
int* replaceElements(int* arr, int arrSize, int* returnSize){
    * returnSize=arrSize;
    int *res=malloc(arrSize*sizeof(int));
    int i,max=arr[arrSize-1];
    res[arrSize-1]=-1;
    for(i=arrSize-2;i>=0;i--){
        res[i]=max;
        if(arr[i]>max) max=arr[i];
    }
    return res;
}
```
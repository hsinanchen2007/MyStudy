### 解题思路
这个解题用的是qsort，因为在真实的战斗中，手写堆排序耗时间，qsort是个不错的选择。
如果用堆排序就每次都建立一个小根堆，根结点就是最小值，记录最小值；接下来把根结点arr[1]和最后一个结点arr[n]交换,在用arr[1]到arr[n-1]建立小根堆继续循环。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(void *a,void *b){
    return *(int*)a-*(int*)b;
}    
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr,arrSize,sizeof(int),comp);
    int *output=(int*)malloc(sizeof(int)*k);
    for(int i=0;i<k;i++){
        output[i]=arr[i];
    }
    *returnSize=k;
    return output;
}
```
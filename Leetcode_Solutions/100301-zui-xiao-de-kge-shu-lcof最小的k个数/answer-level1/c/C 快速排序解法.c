### 解题思路
用快速排序，结束一次排序后，比较k和当前位置的大小，如果当前位置为k或k-1，说明0到k-1位就是最小的k个数

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int low=0,high=arrSize-1;
    int temp=0,*ans=(int*)malloc(sizeof(int)*k);
    while(temp!=k && temp!=k-1){
        temp=QuickSort(arr,low,high);
        if(temp>k) high=temp-1;
        else if(temp<k) low=temp+1;
    }
    for(int i=0;i<k;i++) ans[i]=arr[i];
    *returnSize=k;
    return ans;
}

int QuickSort(int *arr,int low,int high){
    int store=arr[low];
    while(low<high) {
        while(low<high && arr[high]>store) high--;
        if(low<high) arr[low++]=arr[high];
        while(low<high && arr[low]<store) low++;
        if(low<high) arr[high--]=arr[low];
    }
    arr[low]=store;
    return low;
}
```
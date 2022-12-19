### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int Partition(int *arr,int start,int end)
 {
     int temp=arr[start];
     while(start<end)
     {
         while(start<end&&arr[end]>=temp)
            end--;
        arr[start]=arr[end];
        while(start<end&&arr[start]<=temp)
            start++;
        arr[end]=arr[start];
     }
     arr[start]=temp;
     return start;

 }
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(NULL==arr||arrSize<=0||k<=0)
    {
        *returnSize=0;
        return (int *)NULL;
        
    }
    
    int *res=(int *)malloc(k*sizeof(int));
    int start=0;
    int end = arrSize-1;
    int pivot=Partition(arr,start,end);
    while(pivot!=k-1)
    {
        if(pivot>k-1)
        {
            end=pivot-1;
            pivot=Partition(arr,start,end);
        }
        else
        {
            start=pivot+1;
            pivot=Partition(arr,start,end);
        }
    }
    int i=0;
    for(;i<k;i++)
        res[i]=arr[i];
    *returnSize=k;
    return res;

}
```
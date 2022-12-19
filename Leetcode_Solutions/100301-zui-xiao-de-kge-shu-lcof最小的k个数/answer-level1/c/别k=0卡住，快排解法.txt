```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*arrSize);
    *returnSize=k;
    if(k==0){
        return ;
    }
    int numk=f(arr,0,arrSize-1,k-1);
    for(int i=0;i<k;i++)
    {
        res[i]=arr[i];
    }
    return res;
}
int f(int *arr,int low,int high,int k)
{
    int p=partation(arr,low,high);
    if(p==k)return arr[p];
    else if(p>k)return f(arr,low,p-1,k);
    else return f(arr,p+1,high,k);
}
int partation(int *arr,int low,int high)
{
    int temp=arr[low];
    while(low<high)
    {
        while(low<high && arr[high]>=temp)high--;
        arr[low]=arr[high];
        while(low<high && arr[low]<=temp)low++;
        arr[high]=arr[low];
    }
    arr[low]=temp;
    return low;
}
```

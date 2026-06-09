思路特别简单，就是先排序在挑选出相同元素，类似于一次归并排序。
用到的排序方法是堆排序，其中还出现好多错误。发现需要注意的细节有好多。初学者，在努力！
```
void jiaohuan(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


void swap(int *arr,int start,int size)
{
    int dad=start,son=2*dad+1;
    while(son<size)
    {
        if(son+1<size&&arr[son]<arr[son+1])
            son++;
        if(arr[dad]<arr[son])
        {
            jiaohuan(&arr[dad],&arr[son]);
            dad=son;
            son=2*dad+1;
        }
        else
            return;
    }
}


/*
堆排序
*/
void sort(int *arr,int size)
{
    int  i;
    int length=size/2-1;
//构造堆
    for(i=length;i>=0;i--)
    {
        swap(arr,i,size);
    }
    //取顶之后排序
    for(i=size-1;i>0;i--)
    {
        jiaohuan(&arr[0],&arr[i]);
        swap(arr,0,i);
    }
}
    

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(nums1Size==0||nums2Size==0)
    {
        *returnSize=0;
        return NULL;
    }
    
    sort(nums1,nums1Size);
    sort(nums2,nums2Size);
    int len=nums1Size<nums2Size?nums1Size:nums2Size;
    int arr[len];           //变量可能为零//
    int i,j,k=0;
    /*
    for（；表达式1，表达式2；）   则以条件2为主。
    for（；表达式1&表达式2；）    则以先达到条件的表达式为主。
    for（；表达式1|表达式2；）     则以后达到条件的表达式为主。
    */
    
    for(i=0,j=0;i<nums1Size&j<nums2Size&k<len;)//学到了新的东西记在了笔记里
    {
        if(nums1[i]<nums2[j])
            i++;
        else if(nums1[i]>nums2[j])
            j++;
        else if(nums1[i]==nums2[j])
        {
            arr[k++]=nums1[i];
            i++;
            j++;
        }    
    }
    *returnSize=k;
    int *returnarr=(int*)malloc(sizeof(int)*k);
    if(returnarr==NULL)
        exit(0);
    for(i=0;i<k;i++)
    {
        *(returnarr+i)=arr[i];  
    }
    return returnarr;
}


```

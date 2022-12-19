### 解题思路
看具体代码哈~思路很清晰
三种方法，我冥思苦想的另外两种方法从思路上更加清奇，竟然没有库函数快。。。
### 代码
```c
//调用库函数
int cmp(const void *_a,const void* _b)
{
    return *(int *)_a-*(int *)_b;
}
int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums,numsSize,sizeof(int),cmp);
    return nums[numsSize-k];
}
```
我们只要把定位好的元素的下标和k-1比较即可，因为快排的核心就是每次确定一个元素的最终下标
```c
//快排
int QuickSort(int *nums,int low,int high,int k)
{
    int pivot=nums[low];
    int or_low=low,or_high=high;
    while(high>low)
    {
        while(high>low&&nums[high]<=pivot)high--;
        nums[low]=nums[high];
        while(high>low&&nums[low]>=pivot)low++;
        nums[high]=nums[low];
    }
    nums[high]=pivot;
    if(high==k-1)return nums[high];
    else if(high>k-1)return QuickSort(nums,or_low,high-1,k);//仍然在定点的左边
    return QuickSort(nums,high+1,or_high,k);
}
int findKthLargest(int* nums, int numsSize, int k){
    int result= QuickSort(nums,0,numsSize-1,k);
    int i;
    return result;
}
```
堆排序，我们建立一个大顶堆之后，我们每次把堆顶去掉，然后调整k-1次，那么调整之后的堆顶必然是我们的目标元素了。
```c
//堆排序
void Adjust(int *nums,int k,int len)
{
    int i;
    nums[0]=nums[k];
    for(i=2*k;i<=len;i*=2)
    {
        if(i<len&&nums[i]<nums[i+1])i++;
        if(nums[0]>=nums[i])break;
        else
        {
            nums[k]=nums[i];
            k=i;
        }
    }
    nums[k]=nums[0];
}
void BuildMax(int *nums,int len)
{
    int i;
    for(i=len/2;i>0;i--)
    Adjust(nums,i,len);
}
int findKthLargest(int* nums, int numsSize, int k){
    int *lnums=(int *)malloc(sizeof(int)*(numsSize+1));
    int i;
    for(i=numsSize-1;i>=0;i--)
    lnums[i+1]=nums[i];
    BuildMax(lnums,numsSize);//建立大顶堆
    for(i=1;i<k;i++)
    {
        int t=lnums[1];
        lnums[1]=lnums[numsSize-i+1];
        lnums[numsSize-i+1]=t;
        Adjust(lnums,1,numsSize-i);
    }
    return lnums[1];

}


```
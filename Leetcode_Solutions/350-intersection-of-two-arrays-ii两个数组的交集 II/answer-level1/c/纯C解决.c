### 解题思路
思路很简单，先排序，然后稍微利用一下归并的思想。

nums1,nums2，用两个指针指向他们的下标，然后对于相同的，那么肯定是直接存储，然后对于小的是先移动，因为小的必然没有共同的元素。

时间复杂度取决于你所使用的排序算法。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Partition(int *nums,int low, int high)
{
    if(high>low)
    {
        int pivotpos=QuickSort(nums,low,high);
        Partition(nums,pivotpos+1,high);
        Partition(nums,low,pivotpos-1);
    }
}
int QuickSort(int *nums,int low,int high)
{
    int pivot=nums[low];
    while(high>low)
    {
        while(high>low&&nums[high]>=pivot)high--;
        nums[low]=nums[high];
        while(high>low&&nums[low]<=pivot)low++;
        nums[high]=nums[low];
    }
    nums[low]=pivot;
    return high;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    Partition(nums1,0,nums1Size-1);//排序
    Partition(nums2,0,nums2Size-1);

    int index1=0,index2=0;
    
    //for nums
    int *nums=(int *)malloc(sizeof(int)*nums1Size);
    int index=0;

    while(index1<nums1Size&&index2<nums2Size)
    {
        if(nums1[index1]==nums2[index2])//两者相等
        {
            nums[index++]=nums1[index1];
            index1++;
            index2++;    
        }
        else if(nums1[index1]<nums2[index2])
            index1++;
        else
            index2++;
    }
    *returnSize=index;
    return nums;
}
```
### 解题思路
此处撰写解题思路。。

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int numsize=nums2Size+nums1Size;
    int *nums=(int*)malloc(sizeof(int)*numsize);
    int i,j;
    float x;
    if(nums1Size==0)
    {
        if(nums2Size%2==0)
        x=(nums2[nums2Size/2]+nums2[nums2Size/2-1])/2;
        else x=nums2[(nums2Size-1)/2];

    }
    if(nums2Size==0)
    {
        if(nums1Size%2==0)
        x=(nums1[nums1Size/2]+nums1[nums1Size/2-1])/2;
        else x=nums1[(numsize-1)/2];
    }
    for(i=0;i<nums1Size;i++)
        nums[i]=nums1[i];
    for(j=0;j<nums2Size;j++)
        nums[nums1Size+j]=nums2[j];//先让第一个和第二个数组合并
    int m,n,t;
    for(m=0;m<numsize-1;m++)
    for(n=m+1;n<numsize;n++)
    {
        if(nums[m]>nums[n])
        {
        t=nums[m];
        nums[m]=nums[n];
        nums[n]=t;
        }//排序过程
    }
    if(numsize%2==0)
    {
        x=(nums[numsize/2]+nums[numsize/2-1])/2.0;
    }
    else x=nums[(numsize-1)/2];
    return (x);
}
```
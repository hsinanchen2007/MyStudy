### 解题思路
此处撰写解题思路
时间复杂度不符合题目要求，也没有释放内存，改天完善。
两个数组合并为一个有序数组，然后求中位数。
### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalSize=nums1Size+nums2Size;
    int *pArray=(int *)malloc(totalSize*sizeof(int));
    int i=0;
    int j=0;
    int k=0;
    while(i<nums1Size&&j<nums2Size)
    {
        if(nums1[i]<=nums2[j])
        {
            pArray[k++]=nums1[i++];
        }
        else
        {
            pArray[k++]=nums2[j++];
        }
    }
    while(i<nums1Size)
    {
         pArray[k++]=nums1[i++];
    }
    while(j<nums2Size)
    {
         pArray[k++]=nums2[j++];
    }
    if(totalSize%2==0)
    {
        return ((float)pArray[totalSize/2]+(float)pArray[(totalSize/2)-1])/2;
    }
    else
    {
        return (float)pArray[totalSize/2];
    }
}
```
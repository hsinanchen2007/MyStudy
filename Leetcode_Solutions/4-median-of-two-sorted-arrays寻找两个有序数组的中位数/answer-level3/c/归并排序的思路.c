### 解题思路
看到题目的一瞬间就想到找个方法，不过算法复杂度应该o(m+n)，空间复杂度o(m+n)

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *nums3=(int *)malloc(sizeof(int)*(nums1Size+nums2Size));
    int i=0,k=0,j=0;
    while(i<nums1Size&&j<nums2Size)
    {
        if(nums1[i]<=nums2[j])
            nums3[k++]=nums1[i++];
        else
            nums3[k++]=nums2[j++];
    }
    while(i<nums1Size)
    {
        nums3[k++]=nums1[i++];
    }
    while(j<nums2Size)
    {
        nums3[k++]=nums2[j++];
    }
    if((nums1Size+nums2Size)%2==0)
        return ((double)nums3[(nums1Size+nums2Size)/2]+(double)nums3[(nums1Size+nums2Size)/2-1])/2;
    else
        return (double)nums3[(nums1Size+nums2Size)/2];
}
```
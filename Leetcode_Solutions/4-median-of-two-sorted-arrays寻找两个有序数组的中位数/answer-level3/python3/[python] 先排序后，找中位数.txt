首先要明确题意：
这道题想要求解的是两个数组做并操作后的中位数，不是分别求两个数组的中位数再求平均。
利用python自带的`sort` 函数，先排序后找中位数
当数组长度为奇数时，中位数为中间的那个数，
当数组长度为偶数时，中位数为中间的两个数的平均。

代码：
```
def findMedianSortedArrays(nums1, nums2):
    nums=nums1+nums2
    nums=sorted(nums)
    if len(nums)%2==1:
        return nums[len(nums)//2]
    else:
        return (nums[len(nums)//2]+nums[len(nums)//2]-1)/2

```

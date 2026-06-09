1.首先将两个数组合并后排序
2.如果长度为偶数，返回中间两个数和的1/2
3.如果长度为奇数，返回最中间的数
over
代码如下：
```
def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = sorted(nums1 + nums2)
        n = len(nums)
        if n%2 == 0:
            return (nums[n//2]+nums[n//2-1])/2.0
        else:
            return nums[n//2]
```

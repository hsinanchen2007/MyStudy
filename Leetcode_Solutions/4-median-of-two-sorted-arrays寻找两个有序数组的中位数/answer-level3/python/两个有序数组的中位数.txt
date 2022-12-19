# 分析
1. 将两个数组拼接成一个数组nums
2. 对拼接后的数据进行排序
3. 取nums的长度
4. 根据长度的奇偶取中位数

# code
```
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = nums1 + nums2
        nums.sort()
        l = len(nums)
        if l % 2 == 1:
            return nums[l/2]
        else:
            left = nums[l/2 - 1]
            right = nums[l/2]
            return (left + right) / 2.0
```
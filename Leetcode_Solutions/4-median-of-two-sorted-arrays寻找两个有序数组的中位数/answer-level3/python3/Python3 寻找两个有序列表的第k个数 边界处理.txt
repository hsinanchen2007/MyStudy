![image.png](https://pic.leetcode-cn.com/3917d8cb8e19512d07077a2e38699c3093b22111668733b5a0d236cdaa0b8a11-image.png)

这里提供了一种处理边界问题的思路：
```python []
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2) 
        # 如果两个列表的元素数目总和是奇数：那么求第(m+n+1)//2个数
        if m + n & 1:  
            k = (m + n + 1) >> 1
            return self.findKthSortedArrays(nums1, nums2, k)
        # 如果两个列表的元素数目总和是奇数：那么求第(m+n)//2个数和第(m+n)//2个数的平均值
        else:
            k = (m + n) >> 1   
            return 1 / 2 * (self.findKthSortedArrays(nums1, nums2, k)\
                          + self.findKthSortedArrays(nums1, nums2, k + 1))
    
    def findKthSortedArrays(self, nums1, nums2, k):
        m, n = len(nums1), len(nums2)
        # 这里预先给二分法排除两种特例：
        # 一是有空集，
        # 二是前k小的数字都集中在一个集合里
        # 这样二分法就专门来处理前k个数字同时在nums1和nums2的情形
        if not nums1 or k <= n and nums1[0] > nums2[k - 1]:
            return nums2[k - 1]
        if not nums2 or k <= m and nums2[0] > nums1[k - 1]:
            return nums1[k - 1]
        # 注意二分法的lo和hi的边界：
        lo = max(0, k - n - 1)  # 考虑前k个数优先填nums2的情况
        hi = min(m - 1, k - 2)  # 考虑前k个数优先填nums1的情况
        return self.binary(nums1, nums2, k, lo, hi)
    
    def binary(self, nums1, nums2, k, lo, hi):
        if lo < hi:
            mid = (lo + hi) >> 1 
            if nums1[mid] >= nums2[k - mid - 2]:  # 如果nums1中第mid+1个数>=nums2中第k-mid-1个数，那么第k个数要么在nums1[lo, mid]，要么在nums2[k-mid-2,hi]
                hi = mid
            else:
                lo = mid + 1
            return self.binary(nums1, nums2, k, lo, hi)
        else:
            # 如果lo==hi，那么nums1[lo]要么是第k个数，要么是第k个数的前面或后面一个数并且第k个数在nums2中
            # 情形一：nums1[lo]是第k个数
            if nums1[lo] >= nums2[k - lo - 2] and (k - lo - 1 == len(nums2) or nums1[lo] <= nums2[k - lo - 1]):
                return nums1[lo]
            # 情形二：nums[lo]是第k个数的后一个数
            elif k - lo - 1 < len(nums2) and nums1[lo] > nums2[k - lo - 1]:
                return nums2[k - lo - 1]
            # 情形三：nums[lo]是第k个数的前一个数
            else:
                return nums2[k - lo - 2]
```


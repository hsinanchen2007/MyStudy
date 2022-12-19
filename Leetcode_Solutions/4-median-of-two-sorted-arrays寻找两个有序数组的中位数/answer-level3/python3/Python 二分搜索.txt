备注一下，这题还是不太懂...
两个有序数组找第k小的元素的方法：
```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def helper(k:int):
            # 0 <= i < n 0 <= j < m j = k - i
            # nums1[i - 1] <= nums2[j]
            # nums2[j - 1] <= nums1[i]
            left  = max(0, k - len(nums2))
            right = min(len(nums1), k)
            # 二分查找模板 -> 查找i
            while left < right:
                i = (left + right) >> 1
                if nums1[i] < nums2[k - i - 1]:
                    left = i + 1
                else:
                    right = i
            # 第k大的值存在于nums1[i - 1] 和 nums2[j - 1] 中的最大值
            # 判断边界条件， i = 0 / i = k -> j = 0
            if left == 0:
                return nums2[left - 1]
            if left == k:
                return nums1[left - 1]
            return max(nums1[left - 1], nums2[k - left - 1])
        # 让nums1 为短的 减少二分搜索次数
        if len(nums2) > len(nums1):
            nums1, nums2 = nums2, nums1
        n = len(nums2) + len(nums1)
        if n % 2 == 0:
            return (helper(n // 2 + 1) + helper(n // 2)) / 2
        else:
            return helper(n // 2 + 1)

```
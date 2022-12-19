### 解题思路

题目较为简单，将两个数列融合并排序，根据中位数计算方法（奇数个元素或偶数个元素）进行中位数求取。

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        if len(nums1)%2 == 0:
            mid = (nums1[int(len(nums1)/2)]+nums1[int(len(nums1)/2 - 1)])/2
        else:
            mid = nums1[int((len(nums1) - 1)/2)]
        return mid
```
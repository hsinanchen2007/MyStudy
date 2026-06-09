## 思路
+ 很多人已经讲得很清楚了
+ 从第一个数组的最后开始插入
+ 比较第一个数组和第二个数组的指针对应值谁大
+ 添加到数组的最后

## 代码
```Python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        first, second, curr = m - 1, n - 1, len(nums1) - 1
        while curr != -1:
            if second < 0:return nums1
            elif first < 0:nums1[curr], second, curr = nums2[second], second - 1, curr - 1
            elif nums1[first] > nums2[second]:nums1[curr], first, curr = nums1[first], first - 1, curr - 1
            else: nums1[curr], second, curr = nums2[second], second - 1, curr - 1
```
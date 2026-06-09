![捕获.PNG](https://pic.leetcode-cn.com/f3d301127bcab7a499532a32e20634ba6d47b217445eba1a82209cdd73a97472-%E6%8D%95%E8%8E%B7.PNG)

使用二分查找：
    1、对比每次中点元素和其右侧元素值的大小：
        （1）若中点元素值大于右侧元素值，则说明该中点元素位于峰的右侧，将right = mid
        （2）若中点元素值小于右侧元素值，则说明该中点元素位于峰的左侧，将left = mid + 1
    2、当left == right时，打破循环，此时left和right同时指向峰值处
```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        left, right = 0, n - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        return righ
```

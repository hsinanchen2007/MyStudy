取两个数组的中位数


分解步骤
1. 合并数组
2. 新数组排序
3. 分单双长度处理

代码：

```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums.sort()
        n = len(nums)
        if n%2 == 1:
            mid = int(n/2)
            res = nums[mid]
        else:
            mid1 = int(n/2-1)
            mid2 = int(n/2)
            res = (nums[mid1]+nums[mid2])/2
        return res
```

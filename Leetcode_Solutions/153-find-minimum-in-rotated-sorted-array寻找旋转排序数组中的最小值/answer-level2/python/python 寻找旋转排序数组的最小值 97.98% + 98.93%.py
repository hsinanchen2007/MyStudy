### 解题思路
1. 很自然的按照 搜索旋转排序数组 的思路找下去了
2. 一轮 二分查找，时间Ｏ(logn) 空间O(1)
    1. 本质上仍然是一个二分查找，关键点在于判定 target 在那个半区
    2. 可知，任何一次二分,[left,mid] or [mid,right] 有一个半区是有序的；**有序的半区，只需要此半区的第一个元素和min比较即可，不用再递归。**
    3. 判定有序的方法就是 区间头 <= 区间尾 即 nums[left] <= nums[mid] 或者 nums[mid] <= nums[right]
    4. 再通过判定target是否在 有序半区中,来进行下一次二分

### 代码

```python
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        if len(nums) == 1:
            return nums[0]
        m = nums[0]
        res = self.binary_search(nums, 0, len(nums)-1, m)
        return res 
    
    def binary_search(self, nums, l, h, m):
        if (l > h):
            return m
        mid = (l + h) // 2
        if nums[mid] < m:
            m = nums[mid]
        if nums[mid] < nums[h]:
            if nums[mid] < m:
                m = nums[mid]
            m = self.binary_search(nums, l, mid-1, m)
        else:
            if nums[l] < m:
                m = nums[l]
            m = self.binary_search(nums, mid+1, h, m)
            #m = self.binary_search(nums, mid+1, h, m)
            #m = self.binary_search(nums, l, mid-1, m)
        return m
```
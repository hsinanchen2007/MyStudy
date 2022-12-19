### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums or len(nums) == 0:
            return -1
        
        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = start + ((end - start) >> 1)
            if nums[mid] == target:
                return mid
            if nums[mid] > nums[start]:               # 确定有序的子数组, [start, mid]有序
                if nums[start] <= target < nums[mid]: # 确定target是否在[start, mid]有序子数组
                    end = mid
                else:
                    start = mid
            else:                                     # 确定有序的子数组, [mid, end]有序
                if nums[mid] < target <= nums[end]:   # 确定target是否在[mid, end]有序子数组
                    start = mid
                else:                                 # 否则，target在无序子数组
                    end = mid
        if nums[start] == target:
            return start
        if nums[end] == target:
            return end
        return -1
```
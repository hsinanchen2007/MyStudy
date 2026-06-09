### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start, end = 0,len(nums)
        while (end - start) > 1:
            mid = (start + end)//2
            if nums[mid] < target:
                start = mid + 1
            if nums[mid] > target:
                end = mid
            if nums[mid] == target:
                return mid
        else:
            if start < end and nums[start]==target:
                return start
            elif start == end and end < len(nums):
                return start
            else:
                return -1

```
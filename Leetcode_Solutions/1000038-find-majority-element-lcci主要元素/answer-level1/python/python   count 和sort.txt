### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if not nums:
            return None
        nums.sort()
        mid = len(nums)//2
        if nums.count(nums[mid]) >= mid:
            return nums[mid]
        else:
            return -1
```
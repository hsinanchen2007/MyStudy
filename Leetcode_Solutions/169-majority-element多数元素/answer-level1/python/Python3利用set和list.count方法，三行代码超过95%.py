```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        for item in set(nums):
            if nums.count(item) > len(nums) // 2:
                return item
```
在所有 Python3 提交中击败了** 95.42% **的用户
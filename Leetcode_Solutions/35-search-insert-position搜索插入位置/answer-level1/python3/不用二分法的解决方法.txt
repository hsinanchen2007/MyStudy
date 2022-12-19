```python
class Solution:
    def searchInsert(self, nums: [int], target: int) -> int:
        b=False
        for i in range(len(nums)):
            if target<=nums[i]:
                return i
                b=True
                break
        if not b:
            return len(nums)
```
一个for语句直接搞定，为什么好多人这道题都要用二分法？
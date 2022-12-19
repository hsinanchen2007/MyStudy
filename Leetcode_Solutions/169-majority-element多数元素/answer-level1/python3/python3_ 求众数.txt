```python
def majorityElement(nums):
    nums.sort()
    return nums[len(nums) // 2]
```
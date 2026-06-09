```python
def arrayPairSum(nums):
    nums.sort()
    return sum(nums[0::2])
```
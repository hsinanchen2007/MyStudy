```python
def findMaxConsecutiveOnes(nums):
    for i in range(1, len(nums)):
        # 当前索引的值 = 前一个值 + 当前值(两个均不为0), 否则不改变
        nums[i] = nums[i] + nums[i - 1] if nums[i] and nums[i - 1] else nums[i]
    
    return max(nums)

print(findMaxConsecutiveOnes([1,1,0,1,1,1]))
```
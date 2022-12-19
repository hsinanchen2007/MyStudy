```python
def findMaxAverage(nums, k):
    r = _sum = sum(nums[0:k])
    for i in range(k, len(nums)):
        # 通过滑动窗口来计算和
        _sum += nums[i] - nums[i - k]
        r = max(r, _sum)
    return r / k

print(findMaxAverage([1,12,-5,-6,50,3], 4))
```
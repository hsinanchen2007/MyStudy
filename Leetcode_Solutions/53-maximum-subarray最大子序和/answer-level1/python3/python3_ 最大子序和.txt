```python
def maxSubArray(nums):
    for i in range(1, len(nums)):
        # 当前索引i永远存储0~i的最大和
        nums[i] = max(nums[i], nums[i] + nums[i - 1])
    # 返回每个索引最大和的最大值
    return max(nums)

print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
```
```python
def pivotIndex(nums):
    if not nums:
        return -1
    # 通过左数组和不断递增判断的方法
    # 需要注意两种情况: 1. 数组为空. 2. 题目允许中心索引为0, len(nums) - 1的存在.
    _sum, left_sum = sum(nums), 0
    for i in range(0, len(nums)):
        if left_sum * 2 + nums[i] == _sum:
            return i
        left_sum += nums[i]
    return -1

print(pivotIndex([1,7,3,6,5,6]))
```
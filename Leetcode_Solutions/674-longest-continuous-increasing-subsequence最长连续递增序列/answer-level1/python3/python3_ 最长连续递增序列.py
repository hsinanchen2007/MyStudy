```python
def findLengthOfLCIS(nums):
    if not nums:
        return 0
    maxCount, count = 1, 1
    for i in range(len(nums) - 1):
        # 处于递增中
        if nums[i + 1] > nums[i]:
            count += 1
        else:
            # 计算最大长度
            maxCount = max(maxCount, count)
            count = 1
    # 最大长度在数组末尾的情况
    return max(maxCount, count)

print(findLengthOfLCIS([1,3,5,4,7]))
print(findLengthOfLCIS([2,2,2,2,2]))
```
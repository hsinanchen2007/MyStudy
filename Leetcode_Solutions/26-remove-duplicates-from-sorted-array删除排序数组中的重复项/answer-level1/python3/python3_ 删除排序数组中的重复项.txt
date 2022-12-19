```python []
def removeDuplicates(nums):
    # 如果数组为空, 则返回0
    if not nums:
        return 0
    # i为不同元素的数组的长度
    i = 1
    for j in range(1, len(nums)):
        # nums[j]的元素不等于nums[i - 1], 则进行copy, 并且i自增
        if nums[j] != nums[i - 1]:
            nums[i] = nums[j]
            i += 1
    return i

print(removeDuplicates([1,1,2]))
print(removeDuplicates([1,1,2,2]))
print(removeDuplicates([0,0,1,1,1,2,2,3,3,4]))
```

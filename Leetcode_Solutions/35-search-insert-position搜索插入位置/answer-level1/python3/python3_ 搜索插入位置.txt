```python
def searchInsert(nums, target):
    for i, v in enumerate(nums):
        # 找到大于target的元素, 则返回当前索引
        if v >= target:
            return i
    # 说明没有任何元素大于target, 则插入到数组的末尾
    return len(nums)

print(searchInsert([1,3,5,6], 5))
print(searchInsert([1,3,5,6], 2))
print(searchInsert([1,3,5,6], 7))
print(searchInsert([1,3,5,6], 0))
```
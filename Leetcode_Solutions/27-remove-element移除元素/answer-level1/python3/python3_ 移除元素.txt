```python
def removeElement(nums, val):
    # i为不同元素的数组的长度
    i = 0
    for j in range(0, len(nums)):
        # 如果nums[j]不等于val, 则将nums[j]赋值给nums[i]即可, i自增
        if nums[j] != val:
            nums[i] = nums[j]
            i += 1
    return i

print(removeElement([3,2,2,3], 3))
print(removeElement([0,1,2,2,3,0,4,2], 2))
```
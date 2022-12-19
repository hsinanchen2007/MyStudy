```python
def moveZeroes(nums):
    # i为0的索引, j为非0的索引
    i, j = 0, 0
    while j < len(nums) and i < len(nums):
        # 定位0的索引
        if nums[i]:
            i += 1
            j += 1
            continue
        # 说明i应定位到0, j定位到非0
        if nums[j]:
            nums[i] = nums[j]
            # 这里需要将j赋值后的值, 置为0, 并且i自增
            nums[j] = 0
            i += 1
        j += 1
    
nums1 = [1,0,1,1]
moveZeroes(nums1)
print(nums1)
```
```python
def sortColors(nums):
    """
        1. 第一次遍历, 将所有的0放在开头.
        2. 第二次遍历, 将所有的1放在开头.
    """
    i, j = 0, len(nums) - 1
    while i < j:
        while i < j and nums[i] == 0:
            i += 1
        while j > i and nums[j] != 0:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1
    
    i, j = 0, len(nums) - 1
    while i < j:
        if nums[i] == 0:
            i += 1
            continue
        while i < j and nums[i] == 1:
            i += 1
        while j > i and nums[j] == 2:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]
        i += 1
        j -= 1
    
    return nums
    
print(sortColors([2,0,2,1,1,0]))
print(sortColors([2,1,2,0,0,1,2,0,2,1,0,2]))
```
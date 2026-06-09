```python
def checkPossibility(nums):
    def isSort(arr):
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                return False
        return True
    
    for i in range(len(nums) - 1):
        if nums[i] > nums[i + 1]:
            # i, i + 1中的两个元素, 肯定有一个被替换掉
            # 替换掉的情况下, 原数组保持有序, 则为有序
            t1 = isSort(nums[0:i] + nums[i + 1:])
            t2 = isSort(nums[0:i + 1] + nums[i + 2:])
            return t1 or t2
    return True

print(checkPossibility([4,2,3]))
print(checkPossibility([4,2,1]))
```
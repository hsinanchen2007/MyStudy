### 解题思路
方法一：遍历查找
一次遍历，找到返回，找不到那就插入元素

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for index,item in enumerate(nums):
            if item>=target:
                return index
        return len(nums)
```

### 解题思路
方法二：二分

### 代码
```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        size = len(nums)
        if size == 0:
            return 0
        if nums[size - 1] < target:
            return size
        left = 0
        right = size - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left
```
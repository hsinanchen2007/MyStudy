### 解题思路
- 先判断是否存在列表里，是则返回下标
- 不存在则需要遍历升序列表，直到找到比target要大的数字，在该数字前面插入（实际没有插入，只是返回下标）
- 考虑到target可能是整个列表里最大的，也就是应该存在最后，在程序的最后写上列表长度加一作为下表

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        
        if target in nums:
            return nums.index(target)
        for index,num in enumerate(nums):
            if target <=num: return index
        return index+1
```
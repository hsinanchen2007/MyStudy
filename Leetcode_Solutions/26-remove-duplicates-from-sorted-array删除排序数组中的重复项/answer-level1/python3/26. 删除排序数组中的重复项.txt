### 解题思路
从头到尾循环一遍，碰到相同的那么删除，index动，继续判断当前的和删除之后的是否有一样的元素，如果没有的话index就跳转到下一个，直到遍历完整个数组。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        index=0
        while index<len(nums)-1:
            # print(index)
            # print(nums[index])
            if nums[index+1]==nums[index]:
                del nums[index+1]
            else:
                index+=1
        return len(nums)
```
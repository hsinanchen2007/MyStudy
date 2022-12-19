### 解题思路
1、列表的浅拷贝方式[:]
2、range访问列表，比较左右两边的大小，不相同，循环；相同，退出

### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums_copy = nums[:]
        nums_copy.sort()
        for i in range(len(nums)):
            if nums_copy[i] != nums_copy[i+1]:
                continue
            else:
                return nums_copy[i]
```
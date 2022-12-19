### 解题思路
一开始看错了题目以为要找复制的元素的位置，写的麻烦了点

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        #思路，那就找呗
        n = len(nums)
        nums_set = set()
        for i in range(n):
            if nums[i] in nums_set:
                location = nums[i]
            nums_set.add(nums[i])
        for i in range(1,n+1):
            if i not in nums_set:
                val = i
                break
        return [location,val]
```
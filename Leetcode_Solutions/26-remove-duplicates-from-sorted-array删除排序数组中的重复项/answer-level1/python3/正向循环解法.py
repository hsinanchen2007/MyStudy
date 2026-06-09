### 解题思路
rt，因为正向时往后的索引值会变化，所以多加了一个数组的长度判断限制边界

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = len(nums)
        for i in range(1,l):
            while i<l and nums[i] == nums[i-1]:
                nums.pop(i)
                l -= 1
            if i == l:
                return l
            
```
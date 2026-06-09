### 解题思路
我的想法是找到最大数，根据最大数进行左右对比，没有则返回最大数的索引

### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        max_nums = max(nums)
        max_index_nums = nums.index(max_nums)
        for i in range(0,max_index_nums):
            if max_nums < nums[i] * 2:
                return - 1
        for i in range(max_index_nums + 1,len(nums)):
            if max_nums < nums[i] * 2:
                return - 1
        return max_index_nums
```
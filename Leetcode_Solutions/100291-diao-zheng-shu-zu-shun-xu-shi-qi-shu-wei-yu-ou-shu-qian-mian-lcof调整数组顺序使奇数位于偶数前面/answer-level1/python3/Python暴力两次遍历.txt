### 解题思路
因为没有要求原地，直接两次遍历。

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        n = len(nums)
        new_nums = []
        for i in range(n):
            if nums[i]%2 != 0:
                new_nums.append(nums[i])
        for i in range(n):
            if nums[i]%2 == 0:
                new_nums.append(nums[i])
        return new_nums
```
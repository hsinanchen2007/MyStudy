### 解题思路
set减操作

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        all_nums = set(list(range(len(nums)+1)))
        nums = set(nums)
        return list(all_nums - nums)[0]

        
```
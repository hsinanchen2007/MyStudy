### 解题思路
集合会自动合并相同的项

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        res = set()
        for i in range(len(nums)):
            res_len = len(res)
            res.add(nums[i])
            if res_len == len(res):
                return nums[i]
```
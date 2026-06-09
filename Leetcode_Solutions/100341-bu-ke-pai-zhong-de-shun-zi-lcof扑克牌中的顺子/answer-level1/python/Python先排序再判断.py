### 解题思路
排序后首先排除0，然后累加相邻元素差，这是为了在相邻元素差为0（即相邻元素相等）时，直接返回False，如果累加差值<5，则为顺子。

### 代码

```python3
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums.sort()
        count = 0
        for i in range(4):
            if nums[i] == 0:
                continue
            if nums[i+1] - nums[i] == 0:
                return False
            count += nums[i+1] - nums[i]
        if count < 5:
            return True
        return False
```
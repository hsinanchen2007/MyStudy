### 解题思路
小偷偷到第i家的时候，只要选取之前0-（i-2）家的最大就行。
从第三家开始，将数组中每个位置的值改为当前能获取的最大利益。

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) <= 2:
            return max(nums)
        else:
            for i in range(2, len(nums)):
                nums[i] += max(nums[:i-1])
            return max(nums)
```
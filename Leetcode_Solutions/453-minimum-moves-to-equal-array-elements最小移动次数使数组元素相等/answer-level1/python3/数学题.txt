## 思路:

数学题

假设目前数组总和为`sum`，我们需要移动次数为`m`，那么整体数组总和将会增加`m * (n - 1)`，这里的`n`为数组长度，最后数组所有元素都相等为`x`，于是有：

`sum + m * (n - 1) = x * n      `           (1)

我们再设数组最小的元素为`min_val`，`m = x - min_val​`，即 ​`x = m + min_val​`带入(1)得：

`m = sum - min_val * n​`

## 代码:

```python
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums) - len(nums) * min(nums)
```




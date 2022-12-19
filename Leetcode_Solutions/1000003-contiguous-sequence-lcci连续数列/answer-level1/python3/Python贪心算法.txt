### 解题思路
累加，当累加值大于等于0的时候，直接累加并及时更新max值，当累加值小于0的时候，放弃当前累加值。
若存在一个列表全为负数，则max值不更新且恒为0，此时返回列表中的最大值即可。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_, cur = 0, 0
        for i in nums:
            if cur + i >= 0:
                cur += i
                if cur > max_:
                    max_ = cur
            else:
                cur = 0
        return max_ if max_ != 0 else max(nums)
```
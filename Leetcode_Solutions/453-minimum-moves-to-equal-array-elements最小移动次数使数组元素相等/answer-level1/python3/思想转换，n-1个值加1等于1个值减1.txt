题意可理解位每次让一个值减去1，使得所有的值相等，那理想情况就是每个值最终等于最小值。

那么题目就转换为所有值减去最小值的和。


```
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        minvalue = min(nums)
        count = 0
        for i in nums:
            count += i - minvalue
        return count
```

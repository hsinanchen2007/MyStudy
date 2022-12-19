### 解题思路
动态规划问题，个人将输入分两种情况：
    1、全部是负数，
    2、有非负数

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        Max=max(nums)
        dp=0
        if max(nums)<=0:
            return max(nums)
        for i in nums:
            if (dp+i)>0:
                dp+=i
            elif i>0:
                dp=i
            else:
                dp=0
            if dp>Max:
                Max=dp
        return Max

```
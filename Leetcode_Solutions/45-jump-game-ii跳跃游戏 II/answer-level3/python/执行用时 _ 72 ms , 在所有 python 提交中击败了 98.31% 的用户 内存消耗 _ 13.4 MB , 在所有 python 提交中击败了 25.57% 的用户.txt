### 解题思路
借鉴了优秀的题解算法，从后面往前找，每一步找能到达当前位置的最远距离的位置。

### 代码

```python
class Solution(object):
    def jump(self,nums):
        i = len(nums) - 1
        if sum(nums)== i+1 and 0 not in nums:
            return i
        res = 0
        while i>0:
            tempmax = i
            for x in range(i-1,-1,-1):
                if x+nums[x]>=i:
                    tempmax = x
            i = tempmax
            res += 1
        return res
```
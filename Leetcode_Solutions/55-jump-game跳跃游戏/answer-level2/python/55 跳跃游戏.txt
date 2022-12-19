### 解题思路
关键是要能理解：最远能到达某个位置，就一定能到达它前面的任何位置。

### 代码

```python
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max_bound=0
        n=len(nums)
        end=0
        for i in range(n):
            max_bound=max(max_bound,nums[i]+i)
            if(i==end):
                end=max_bound
            if(end>=n-1):
                return True
        return False

```
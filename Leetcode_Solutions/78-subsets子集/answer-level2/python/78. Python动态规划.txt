### 解题思路
这道题很明显可以用动态规划做，如果令dp[i]代表nums[:i + 1]子集的所有幂集，那么dp[i] = dp[i - 1]中所有元素加上nums[i]或者不加上nums[i]，下面的实现只不过没有显示设置dp列表，因为dp[i - 1]之前的状态没必要保存。

### 代码

```python
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        res = [[]]
        temp = []
        for num in nums:
            for x in res:
                temp.append(x + [num])
            res += temp
            temp = []
        return res
```
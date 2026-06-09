### 解题思路
名字自己起的。
做法有点类似动态规划算法，假设我们已经有了一个两层list，它对前m个数字是满足要求的输出。
现在我们假设要多加一个m+1位的数字，那只需要把这个第m+1个的数字依次插入到现在的内层的list的数字间隔中（插入位置包含首尾，一共有m+1个空位）即可。

### 代码

```python
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 1:
            return [nums]
        res = [[[nums[0]]], [[nums[0]]]]
        k= 0
        for i in range(1, len(nums)):
            res[1-k] = []
            for j in range(i+1):
                res[1-k].extend([z[:j] + [nums[i]] + z[j:] for z in res[k]])
            k = 1 - k
        return res[k]

            
```
### 解题思路
1. 逐层插入

### 代码

```python
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        if n < 2: return [nums]
        
        last_res = [[nums[0]]]
        for i in range(1, n):
            cur_res = []
            for j in range(len(last_res)):
                for k in range(i + 1):
                    cur_res.append(last_res[j][:k]+[nums[i]]+last_res[j][k:])
            last_res = cur_res
        return last_res

```
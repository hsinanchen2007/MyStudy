全排列+去重+剪枝 【python】

```python
class Solution(object):

    def numSquarefulPerms(self, A):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = A
        nums.sort()
        res = []
        def backtrack(nums, tmp):
            if not nums:
                res.append(tmp)
                return 
            for i in range(len(nums)):
                # 去重
                if i and nums[i]==nums[i-1]:
                    continue
                # 剪枝
                if not tmp or math.sqrt(tmp[-1]+nums[i]) % 1 == 0:
                    backtrack(nums[:i] + nums[i+1:], tmp + [nums[i]])
        backtrack(nums, [])
        return len(res)
```

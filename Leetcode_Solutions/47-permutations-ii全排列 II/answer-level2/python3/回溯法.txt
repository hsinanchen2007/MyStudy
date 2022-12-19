按照自己思路写完，再看别人的答案，才知道那个操作叫剪枝

```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        v = {}
        for i in range(len(nums)):
            v[i] = False
        def bf(path):
            pre = []    # 每次递归都要重置
            if len(path) == len(nums):
                res.append(path)
            for i in range(len(nums)):
                if nums[i] not in pre and v[i] == False:
                    pre.append(nums[i])
                    v[i] = True
                    bf(path + [nums[i]])
                    v[i] = False
        bf([])
        return res
```

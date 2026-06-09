动态规划

```python3
class Solution:
    def subsetsWithDup(self, nums):

        res = []
        nums.sort()
        res.append([])
        res.append([nums[0]])
        for i in range(1, len(nums)):
            # if nums[i] == nums[i-1]:
            #     continue
            res += [tt+[nums[i]] for tt in res if tt+[nums[i]] not in res]
        return res
```

回溯法
```
class Solution:
    def subsetsWithDup(self, nums):
        result = []
        nums.sort()
        self.helper(nums, 0, [], result)
        return result

    def helper(self, nums, start, tmp, result):
        if tmp not in result:
            result.append(tmp[:])
        for i in range(start, len(nums)):
            tmp.append(nums[i])
            self.helper(nums, i+1, tmp, result)
            tmp.pop()
```


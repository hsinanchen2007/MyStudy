### 解题思路
先排序，然后开始搜。
易读易理解。

### 代码

```python3
class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 4 != 0:
            return False
        target = total//4
        nums.sort()
        return self.dfs(nums, target, 0, 0, {})
        
    def dfs(self, nums, target, tmp, res, memo):
        if not nums:
            if res == 4:
                return True
            return False

        if (tuple(nums), tmp, res) in memo:
            return memo[(tuple(nums), tmp, res)]

        for i in range(len(nums)):
            if tmp + nums[i] == target:
                if self.dfs(nums[:i] + nums[i+1:], target, 0, res + 1, memo):
                    memo[(tuple(nums), tmp, res)] = True
                    return True
            elif tmp + nums[i] < target:
                if self.dfs(nums[:i]+nums[i+1:], target, tmp + nums[i], res, memo):
                    memo[(tuple(nums), tmp, res)] = True
                    return True
            else:
                break
        memo[(tuple(nums), tmp, res)] = False
        return False
```
### 解题思路
backtrack条件提前pos<N and target < nums[pos]
这样不用算target<0
### 代码
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:

        div, remain = divmod(sum(nums), 2)
        if remain != 0:
            return False
        N = len(nums)
        nums.sort(reverse=True)
        def _dfs(target, pos):
            if target == 0:
                return True   
            if pos<N and target < nums[pos]:
                return False
            for i in range(pos, N):
                if _dfs(target-nums[i], i+1):
                    return True
            return False
        return _dfs(div, 0)

# if target == 0:
#     return True
# if (target < 0 or pos == N or target < nums[pos]):
#     return False

# nextTarget = target - nums[pos]
# if _dfs(nextTarget, pos + 1):
#     return True
# else:
#     return _dfs(target, pos + 1);
```

### 解题思路
#判断当前数字和上一个数字是否相同 重点是i>start 而不是0

### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        choices = len(nums)
        res = []
        def backtrack(track, start):
            res.append(track[:])
            for i in range(start, choices):
                if i >start and nums[i-1] == nums[i]:
                    continue
                track.append(nums[i])
                backtrack(track,i + 1)
                track.pop()
        backtrack([],0)
        return res
```
### 解题思路
我太难了，怎么才能去除result中的[1,4,4]和[4,1,4]这种子集呢，我只能想到sort

### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        def backtrack(start, track, length):
            if len(track)==length:
                track.sort()
                if track not in result:
                    result.append(track[:])
                return
            for i in range(start, len(nums)):
                backtrack(i+1, track+[nums[i]], length)
        for i in range(len(nums)+1):
            backtrack(0, [], i)
        return result
            
```
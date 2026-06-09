### 解题思路
找好传递的变量，写好输出条件

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        def backtrack(start,track,length):
            if len(track) == length:
                result.append(track[:])
                return
            for i in range(start,len(nums)):
                backtrack(i+1, track+[nums[i]], length)
        for i in range(len(nums)+1):
            backtrack(0, [], i)
        return result

```
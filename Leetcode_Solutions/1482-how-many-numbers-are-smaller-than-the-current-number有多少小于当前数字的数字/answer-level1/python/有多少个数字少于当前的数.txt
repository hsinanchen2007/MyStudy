### 解题思路
执行用时：击败5.01%用户
内存消耗：击败100%用户

### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        out = []
        for i in range(len(nums)):
            num = 0
            for j in range(len(nums)):
                if nums[j] == nums[i]:
                    continue
                else:
                    if nums[j] < nums[i]:
                        num += 1
            out += [num]
        return out

```
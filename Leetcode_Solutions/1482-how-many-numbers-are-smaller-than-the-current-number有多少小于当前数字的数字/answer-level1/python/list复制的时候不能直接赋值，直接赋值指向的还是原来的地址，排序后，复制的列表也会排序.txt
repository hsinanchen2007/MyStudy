### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        r = []
        newNums = nums[:]
        nums.sort()
        for m in newNums:            
            r.append(nums.index(m))
        return r



```
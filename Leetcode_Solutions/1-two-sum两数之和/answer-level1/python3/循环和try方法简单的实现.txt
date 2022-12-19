### 解题思路
数不能重复，try排除重复可能

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            try:
                j = nums.index(target - nums[i],i+1)
                return [i,j]
            except:
                continue

```
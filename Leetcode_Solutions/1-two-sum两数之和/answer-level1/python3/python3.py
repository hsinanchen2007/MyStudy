### 解题思路

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) :
        dic = {}
        for i in range(len(nums)):
            dic[nums[i]] = i
        for i in range(len(nums)):
            x = target - nums[i]
            if x in dic and dic[x] != i:
                return [i, dic[x]]




```
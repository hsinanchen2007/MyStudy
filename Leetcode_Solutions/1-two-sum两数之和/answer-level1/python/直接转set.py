### 解题思路
直接转set

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numset=set(nums)
        for i in range(len(nums)):
            if target-nums[i] in numset:
                j=nums.index(target-nums[i])
                if i!=j:
                    return [i,j]
```
### 解题思路
先排序，再根据与前后值得关系判断是否唯一。

### 代码

```python3
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        res = []
        nums.sort()
        if nums[0] != nums[1]:
            res.append(nums[0])
        if nums[len(nums) - 1] != nums[len(nums) - 2]:
            res.append(nums[len(nums)-1])
        for i in range(1,len(nums)-1):
            if len(res) == 2:
                return res
            if nums[i] != nums[i-1] and nums[i] != nums[i+1]:
                res.append(nums[i])
        return res
```
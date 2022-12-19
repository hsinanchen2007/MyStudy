### 解题思路
rt

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def func(nums, temp):
            if not nums:
                res.append(temp)
                return
            for i in range(len(nums)):
                func(nums[:i] + nums[i+1:], temp + [nums[i]])
        func(nums, [])
        return res
```
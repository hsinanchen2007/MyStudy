### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        memo_max = 1
        memo_min = 1
        res = nums[0]
        for i in range(len(nums)):
            temp_list = [memo_max * nums[i], nums[i], memo_min * nums[i]]

            memo_max=max(temp_list)

            memo_min=min(temp_list)

            res = max(res, memo_max)
        
        return res
```
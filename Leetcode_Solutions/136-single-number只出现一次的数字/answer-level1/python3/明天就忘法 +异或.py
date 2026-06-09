### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res=0
        n=len(nums)
        for i in range(n):
            res^=nums[i]
        return res
```
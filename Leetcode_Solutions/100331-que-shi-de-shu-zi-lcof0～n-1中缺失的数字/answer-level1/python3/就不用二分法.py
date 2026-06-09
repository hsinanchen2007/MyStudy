### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for i,num in enumerate(nums):
            if i != num:
                return i
            
            
            
            
            
        # 加和法 
        res = (len(nums) * (len(nums)+1)) >> 1 # 首项加尾项 除以个数的一半
        return res - sum(nums)
```
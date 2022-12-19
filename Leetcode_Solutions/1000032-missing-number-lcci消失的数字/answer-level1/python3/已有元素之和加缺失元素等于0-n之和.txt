### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return (1+len(nums))*len(nums)//2-sum(nums)
```
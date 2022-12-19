### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        """
        set_standard - set(nums) == lack --> 3
        
        
        式二：sum(set_standard) - sum(nums) == diff --> 1
        
        式三：diff = sum(set_standard) - lack + x
        
        求x
        
        二三得：lack - x = diff
        x = lack - diff
        
        """
        
        
        lack = (set(range(1, len(nums) + 1)) - set(nums)).pop()
        
        diff = sum(range(1, len(nums) + 1)) - sum(nums)
        
        return [lack - diff, lack]
```
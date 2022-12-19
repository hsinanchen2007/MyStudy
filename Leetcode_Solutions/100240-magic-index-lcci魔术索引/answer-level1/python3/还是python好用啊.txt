### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        res=-1
        for i in range(len(nums)):
            if nums[i]==i:
                res=i
                break
        
        return res
```
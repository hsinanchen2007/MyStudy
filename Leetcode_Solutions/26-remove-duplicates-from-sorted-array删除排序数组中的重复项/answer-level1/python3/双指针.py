### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=1
        
        for j in range(len(nums)):
            if nums[j]!=nums[i-1]:
                nums[i]=nums[j]
                i=i+1
        return i
```
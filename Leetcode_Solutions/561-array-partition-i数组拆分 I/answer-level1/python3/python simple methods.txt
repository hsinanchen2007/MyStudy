### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        '''
        return sum(sorted(nums)[::2])
        '''
        nums.sort()
        res = 0
        for i in range(1,len(nums),2):
            m = min(nums[i-1],nums[i])
            res+=m
        return res
```
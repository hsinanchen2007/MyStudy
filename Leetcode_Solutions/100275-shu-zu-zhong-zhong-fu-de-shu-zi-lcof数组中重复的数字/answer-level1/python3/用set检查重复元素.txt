### 解题思路
用set检查重复元素

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        ans = set()
        for i in range(len(nums)):
            if(nums[i] in ans):
                return nums[i]
            else:
                ans.add(nums[i])
            
```
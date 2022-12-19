### 解题思路
纯数学法
+(n-1)=>-1

### 代码

```python3
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums)-nums[0]*len(nums) 
```
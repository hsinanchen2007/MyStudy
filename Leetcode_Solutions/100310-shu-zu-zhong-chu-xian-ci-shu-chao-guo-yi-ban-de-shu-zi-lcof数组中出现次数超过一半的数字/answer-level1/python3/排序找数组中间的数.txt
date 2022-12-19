### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
      nums.sort()
      return nums[int(len(nums)/2)]
    
```
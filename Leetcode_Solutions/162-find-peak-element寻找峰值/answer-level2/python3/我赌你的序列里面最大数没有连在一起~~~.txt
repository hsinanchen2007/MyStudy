### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        return nums.index(max(nums))
```
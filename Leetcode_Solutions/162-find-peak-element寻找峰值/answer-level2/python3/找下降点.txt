### 解题思路
下降直接return。

### 代码

```python3
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        for item in range(len(nums)-1):
            if nums[item] > nums[item+1]:
                return item
        return len(nums)-1
```
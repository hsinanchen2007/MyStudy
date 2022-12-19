### 解题思路
先排序，再取中位数

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[int(len(nums)/2)]
```
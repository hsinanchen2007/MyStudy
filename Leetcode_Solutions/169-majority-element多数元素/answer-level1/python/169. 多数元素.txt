### 解题思路
排序后，输出中间一个元素

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        mid = len(nums) // 2
        return nums[mid]

```
### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        another_nums = [target - i for i in nums]
        i = j = -1
        for i in range(len(nums)):
            try:
                j = nums[i+1:].index(another_nums[i]) + i + 1
            except ValueError as e:
                j = None
            if j:
                break
        return [i, j]
```
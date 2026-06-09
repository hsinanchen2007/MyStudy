### 解题思路
此处撰写解题思路
穷举法，遍历所有可能情况

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for i in range(0, length-1, 1):
            for j in range( i+1, length, 1):
                if nums[i] + nums[j] == target:
                    return [i, j]
```
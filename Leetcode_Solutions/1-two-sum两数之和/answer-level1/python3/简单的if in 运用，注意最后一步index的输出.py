### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums)-1):
            num1 = nums[i]
            num2 = target - num1
            if num2 in nums[i+1:]:
                return [i, i+1+nums[i+1:].index(num2)]
                break
```
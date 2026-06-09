### 解题思路
整数数组排序，按顺序俩俩(i, i+1)配对，返回不匹配的元素即可。

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = nums.sort()
        start = 0
        while start < len(nums) - 1:
            if nums[start] != nums[start + 1]:
                return nums[start]
            else:
                start += 2
        else:
            return nums[-1]
            
```
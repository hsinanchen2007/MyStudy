### 解题思路
![TIM截图20200227115442.png](https://pic.leetcode-cn.com/3fcb15872ce0e8dd2d2f1c9b9fa2aa726ab5ad13712168f57494217e3423eedf-TIM%E6%88%AA%E5%9B%BE20200227115442.png)

双指针遍历数组`nums`，`start, end = 0, len(nums)-1`
如果和小于`target`， `end -= 1`
如果和大于`target`， `start += 1`
否则返回`[nums[start], nums[end]]`

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        start, end = 0, len(nums)-1
        while start < end:
            if nums[start]+nums[end] > target:
                end -= 1
            elif nums[start]+nums[end] < target:
                start += 1
            else:
                return [nums[start], nums[end]]
```
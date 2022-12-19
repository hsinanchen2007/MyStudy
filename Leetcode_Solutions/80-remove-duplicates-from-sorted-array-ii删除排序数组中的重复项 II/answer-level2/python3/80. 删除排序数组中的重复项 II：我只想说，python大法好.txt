![image.png](https://pic.leetcode-cn.com/a3d73508ff86eff532e95221e3fbd3bf18ed6a335003141f1ba310e72d7b9498-image.png)

从后往前遍历，直接删值就很有效

```python []
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums) - 3, -1, -1):
            if nums[i] == nums[i + 1] == nums[i + 2]:
                nums.pop(i)
```

# 二分法

思路：每次选取最中心的一个数，分为两种状态：

- 包含这个数：`nums[c] + f(nums[:c - 1]) + f(nums[c + 2:])`
- 不包含这个数：`f(nums[:c]) + f(nums[c + 1:])`

这两种状态的最大值即为结果

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        l = len(nums)
        if l == 0:
            return 0
        elif l == 1:
            return nums[0]
        else:
            c = l // 2
            yes = nums[c] + self.massage(nums[:c - 1]) + self.massage(nums[c + 2:])
            no = self.massage(nums[:c]) + self.massage(nums[c + 1:])
            return max(yes, no)
```

# 复杂度

时间复杂度：O(log(N))

空间复杂度：O(1)
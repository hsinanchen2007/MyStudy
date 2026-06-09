```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums, r, end = sorted(nums), float('inf'), len(nums) - 1
        for c in range(len(nums) - 2):
            i, j = max(c + 1, bisect.bisect_left(nums, target - nums[end] - nums[c], c + 1, end) - 1), end
            while r != target and i < j:
                s = nums[c] + nums[i] + nums[j]
                r, i, j = min(r, s, key=lambda x: abs(x - target)), i + (s < target), j - (s > target)
        return r
```
- float('inf') = 正无穷
- 排序，遍历，双指针，O(N^2) 时间复杂度，二分法初始化
- 排序是为了使用双指针，首先遍历得到索引 c，然后计算 c，左指针 i，右指针 j 对应数字之和，如果大于 target，j 向内移动，否则 i 向内移动
- i 的初始值不是 c + 1，是为了减少计算量，用二分法得到一个合理的初始值
